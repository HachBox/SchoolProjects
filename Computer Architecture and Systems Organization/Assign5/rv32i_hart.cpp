/*
 * CSCI 463 - Assignment 5
 *
 * Author: Harry Chieng
 *
 * RISC-V Simulator - rv32i_hart.cpp
 *
 *****************************************/

#include "rv32i_hart.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using std::setw;
using std::setfill;
using std::ostream;
using std::left;
using std::string;
using std::cout;
using std::endl;

void rv32i_hart::exec ( uint32_t insn , ostream* pos) {
	int opcode = get_opcode(insn);	
	switch(opcode) {
		default:	exec_illegal_insn(insn, pos); return;
		case opcode_lui:	exec_lui(insn,pos); return;	
		case opcode_auipc: 	exec_auipc(insn, pos); return;
		case opcode_jal:	exec_jal(insn, pos); return;	
		case opcode_jalr:	exec_jalr(insn, pos); return;	
		case opcode_btype:
					switch (get_funct3(insn))
					{
						default: exec_illegal_insn(insn, pos); return;
						case funct3_beq: exec_btype(insn, pos, "beq"); return;
						case funct3_bne: exec_btype(insn, pos, "bne"); return;
						case funct3_blt: exec_btype(insn, pos, "blt"); return;
						case funct3_bge: exec_btype(insn, pos, "bge"); return;
						case funct3_bltu: exec_btype(insn, pos, "bltu"); return;
						case funct3_bgeu: exec_btype(insn, pos, "bgeu"); return;
					}
		case opcode_load_imm: 
					switch (get_funct3(insn)) {
						default: exec_illegal_insn(insn, pos); return;
						case funct3_lb: exec_itype_load(insn, "lb", pos); return;
						case funct3_lh: exec_itype_load(insn, "lh", pos); return;
						case funct3_lw: exec_itype_load(insn, "lw", pos); return;
						case funct3_lbu: exec_itype_load(insn, "lbu", pos); return;
						case funct3_lhu: exec_itype_load(insn, "lhu", pos); return;
					}

		case opcode_stype: 
					switch (get_funct3(insn)) {
						default: exec_illegal_insn(insn, pos); return;
						case funct3_sb: exec_stype(insn, "sb", pos); return;
						case funct3_sh: exec_stype(insn, "sh", pos); return;
						case funct3_sw: exec_stype(insn, "sw", pos); return;
					}

		case opcode_alu_imm:
					switch (get_funct3(insn))
					{
						default: exec_illegal_insn(insn, pos); return;
						case funct3_add: exec_itype_alu(insn, "addi", get_imm_i(insn), pos); return;
						case funct3_slt: exec_itype_alu(insn, "slti", get_imm_i(insn), pos); return;
						case funct3_sltu: exec_itype_alu(insn, "sltiu", get_imm_i(insn), pos); return;
						case funct3_xor: exec_itype_alu(insn, "xori", get_imm_i(insn), pos); return;
						case funct3_or: exec_itype_alu(insn, "ori", get_imm_i(insn), pos); return;
						case funct3_and: exec_itype_alu(insn, "andi", get_imm_i(insn), pos); return;
						case funct3_sll: exec_itype_alu(insn, "slli", get_imm_i(insn)%XLEN, pos); return;
						case funct3_srx: 
								 switch(get_funct7(insn))
								 {

									 default: exec_illegal_insn(insn, pos); return;
									 case funct7_sra: exec_itype_alu(insn, "srai", get_imm_i(insn)%XLEN, pos); return;
									 case funct7_srl: exec_itype_alu(insn, "srli", get_imm_i(insn)%XLEN, pos); return;
								 }
					}
		case opcode_rtype: 
					switch (get_funct3(insn)) {
						default: exec_illegal_insn(insn, pos); return;
						case funct3_add: 
							 switch(get_funct7(insn)) {
								 default: exec_illegal_insn(insn, pos);return;
								 case funct7_add: exec_rtype(insn, "add", pos); return;
								 case funct7_sub: exec_rtype(insn, "sub", pos); return;
							 }
						case funct3_sll: exec_rtype(insn, "sll", pos); return; 
						case funct3_srx: 
								 switch(get_funct7(insn))
								 {
									 default: exec_illegal_insn(insn, pos); return;
									 case funct7_sra: exec_rtype(insn, "sra", pos); return;
									 case funct7_srl: exec_rtype(insn, "srl", pos); return;
								 }
						case funct3_slt: exec_rtype(insn, "slt", pos); return;
						case funct3_sltu: exec_rtype(insn, "sltu", pos); return;
						case funct3_xor: exec_rtype(insn, "xor", pos); return;
						case funct3_or: exec_rtype(insn, "or", pos); return;
						case funct3_and: exec_rtype(insn, "and", pos); return;
					}
		case opcode_system:
					if (insn == insn_ebreak) {
						exec_ebreak(insn, pos); 
						return; 
					}
					switch (get_funct3(insn)) {
						default: exec_illegal_insn(insn, pos); break;
						case funct3_csrrs: exec_csrrs(insn, pos); return;
					}
	}
}

void rv32i_hart::exec_illegal_insn(uint32_t insn , std::ostream * pos) {
	if(pos)
		*pos << render_illegal_insn(insn);
	halt = true;
	halt_reason = "Illegal instruction";
}

void rv32i_hart::exec_lui (uint32_t insn, ostream* pos) {
	uint32_t rd = get_rd (insn);	
	int32_t imm = get_imm_u(insn);

	if(pos) {
		string s = render_lui(insn);
		*pos << setw (instruction_width) << setfill (' ') << left << s;
		*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(imm);
	}
	regs.set(rd,imm);
	pc += 4;
}

void rv32i_hart::exec_auipc (uint32_t insn , ostream*pos) {
	uint32_t rd = get_rd(insn);
	uint32_t imm_u = get_imm_u (insn);
	int32_t val = (pc + imm_u);
	if (pos) {
		std::string s = render_auipc(insn);
		*pos << setw(instruction_width) << setfill (' ') << left << s;
		*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(pc) << " + " << hex::to_hex0x32(imm_u) << " = " <<  hex::to_hex0x32(val);
	}
	regs.set(rd, val);
	pc += 4;
}

void rv32i_hart::exec_jal (uint32_t insn, ostream* pos) {
	uint32_t rd = get_rd (insn);	
	int32_t imm_j = get_imm_j(insn);
	int pcrel_21 = pc + imm_j; 
	int32_t val = (pc + 4);

	if(pos) {
		string s = render_jal(pc, insn);
		*pos << setw (instruction_width) << setfill (' ') << left << s;
		*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(val) << ",  pc = " << hex::to_hex0x32(pc) << " + " << hex::to_hex0x32(imm_j) << " = " << hex::to_hex0x32(pcrel_21);
	}
	regs.set(rd,val);
	pc += imm_j;
}

void rv32i_hart::exec_jalr (uint32_t insn, ostream* pos) {
	uint32_t rd = get_rd(insn);
	uint32_t imm_i = get_imm_i(insn);
	int rs1 = regs.get(get_rs1(insn));
	int32_t val = (pc + 4);

	if(pos) {
		string s = render_jalr(insn);
		*pos << setw(instruction_width) << setfill(' ') << left << s;
		*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(val) << ",  pc = (" << hex::to_hex0x32(imm_i) << " + " << hex::to_hex0x32(rs1) << ") & " << hex::to_hex0x32(~1) << " = " << hex::to_hex0x32((rs1+imm_i)&~1);
	}
	regs.set(rd, val);
	pc = (rs1 + imm_i)&~1; 
}

void rv32i_hart::exec_btype(uint32_t insn, ostream* pos, string mnemonic) {
	if(mnemonic == "beq") {
		int32_t imm_b = get_imm_b(insn);
		int rs1 = regs.get(get_rs1(insn));
		int rs2 = regs.get(get_rs2(insn));
		int32_t val = rs1 == rs2 ? imm_b : 4;
		int pcrel_13 = pc + val;

		if(pos) {
			string s = render_btype(pc, insn, "beq");
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << "pc" << " += (" << hex::to_hex0x32(rs1) << " == " << hex::to_hex0x32(rs2) << " ? " << hex::to_hex0x32(imm_b) << " : 4) = " << hex::to_hex0x32(pcrel_13);
		}
		pc += val;
	}
	else if(mnemonic == "bge") {
		int32_t imm_b = get_imm_b(insn);
		int rs1 = regs.get(get_rs1(insn));
		int rs2 = regs.get(get_rs2(insn));
		int32_t val = rs1 >= rs2 ? imm_b : 4;
		int pcrel_13 = pc + val;

		if(pos) {
			string s = render_btype(pc, insn, "bge");
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << "pc" << " += (" << hex::to_hex0x32(rs1) << " >= " << hex::to_hex0x32(rs2) << " ? " << hex::to_hex0x32(imm_b) << " : 4) = " << hex::to_hex0x32(pcrel_13);
		}
		pc += val;
	}
	else if(mnemonic == "bgeu") {
		int32_t imm_b = get_imm_b(insn);
		int rs1 = regs.get(get_rs1(insn));
		int rs2 = regs.get(get_rs2(insn));
		int32_t val = ((uint32_t) rs1 >= (uint32_t) rs2) ? imm_b : 4;
		int pcrel_13 = pc + val;

		if(pos) {
			string s = render_btype(pc, insn, "bgeu");
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << "pc" << " += (" << hex::to_hex0x32(rs1) << " >=U " << hex::to_hex0x32(rs2) << " ? " << hex::to_hex0x32(imm_b) << " : 4) = " << hex::to_hex0x32(pcrel_13);
		}
		pc += val;
	}
	else if(mnemonic == "blt") {
		int32_t imm_b = get_imm_b(insn);
		int rs1 = regs.get(get_rs1(insn));
		int rs2 = regs.get(get_rs2(insn));
		int32_t val = (rs1 < rs2) ? imm_b : 4;
		int pcrel_13 = pc + val;

		if(pos) {
			string s = render_btype(pc, insn, "blt");
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << "pc" << " += (" << hex::to_hex0x32(rs1) << " < " << hex::to_hex0x32(rs2) << " ? " << hex::to_hex0x32(imm_b) << " : 4) = " << hex::to_hex0x32(pcrel_13);
		}
		pc += val;
	}
	else if(mnemonic == "bltu") {
		int32_t imm_b = get_imm_b(insn);
		int rs1 = regs.get(get_rs1(insn));
		int rs2 = regs.get(get_rs2(insn));
		int32_t val = ((uint32_t) rs1 < (uint32_t) rs2) ? imm_b : 4;
		int pcrel_13 = pc + val;

		if(pos) {
			string s = render_btype(pc, insn, "bltu");
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << "pc" << " += (" << hex::to_hex0x32(rs1) << " <U " << hex::to_hex0x32(rs2) << " ? " << hex::to_hex0x32(imm_b) << " : 4) = " << hex::to_hex0x32(pcrel_13);
		}
		pc += val;
	}
	else if(mnemonic == "bne") {
		int32_t imm_b = get_imm_b(insn);
		uint32_t rs1 = regs.get(get_rs1(insn));
		uint32_t rs2 = regs.get(get_rs2(insn));
		int32_t val = ((rs1 != rs2) ? imm_b : 4);
		int pcrel_13 = pc + val;

		if(pos) {
			string s = render_btype(pc, insn, "bne");
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << "pc" << " += (" << hex::to_hex0x32(rs1) << " != " << hex::to_hex0x32(rs2) << " ? " << hex::to_hex0x32(imm_b) << " : 4) = " << hex::to_hex0x32(pcrel_13);
		}
		pc += val;
	}
}

void rv32i_hart::exec_itype_load(uint32_t insn, string mnemonic, ostream* pos) {
	if(mnemonic == "lb") {
		uint32_t rd = get_rd(insn);
		int32_t imm_i = get_imm_i(insn);
		int rs1 = regs.get(get_rs1(insn));
		int32_t val = mem.get8_sx(rs1 + imm_i);

		if(pos) {
			string s = render_itype_load(insn, "lb");
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << render_reg(rd) << " = sx(m8(" << hex::to_hex0x32(rs1) << " + " << hex::to_hex0x32(imm_i) << ")) = " << hex::to_hex0x32(val);
		}
		regs.set(rd, val);
		pc += 4;
	}
	else if(mnemonic == "lh") {
		uint32_t rd = get_rd(insn);
		int32_t imm_i = get_imm_i(insn);
		int rs1 = regs.get(get_rs1(insn));
		int32_t val = mem.get16_sx(rs1 + imm_i);

		if(pos) {
			string s = render_itype_load(insn, "lh");
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << render_reg(rd) << " = sx(m16(" << hex::to_hex0x32(rs1) << " + " << hex::to_hex0x32(imm_i) << ")) = " << hex::to_hex0x32(val);
		}
		regs.set(rd, val);
		pc += 4;
	}
	else if(mnemonic == "lw") {
		uint32_t rd = get_rd(insn);
		int32_t imm_i = get_imm_i(insn);
		int rs1 = regs.get(get_rs1(insn));
		int32_t val = mem.get32_sx(rs1 + imm_i);

		if(pos) {
			string s = render_itype_load(insn, "lw");
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << render_reg(rd) << " = sx(m32(" << hex::to_hex0x32(rs1) << " + " << hex::to_hex0x32(imm_i) << ")) = " << hex::to_hex0x32(val);
		}	
		regs.set(rd, val);
		pc += 4;
	}

	else if(mnemonic == "lhu") {
		uint32_t rd = get_rd(insn);
		int32_t imm_i = get_imm_i(insn);
		int rs1 = regs.get(get_rs1(insn));
		int32_t val = mem.get16((uint32_t)rs1 + (uint32_t)imm_i);

		if(pos) {
			string s = render_itype_load(insn, "lhu");
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << render_reg(rd) << " = zx(m16(" << hex::to_hex0x32(rs1) << " + " << hex::to_hex0x32(imm_i) << ")) = " << hex::to_hex0x32(val);
		}	
		regs.set(rd, val);
		pc += 4;
	}

	else if(mnemonic == "lbu") {
		uint32_t rd = get_rd(insn);
		int32_t imm_i = get_imm_i(insn);
		int rs1 = regs.get(get_rs1(insn));
		int32_t val = mem.get8(rs1 + imm_i);

		if(pos) {
			string s = render_itype_load(insn, "lbu");
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << render_reg(rd) << " = zx(m8(" << hex::to_hex0x32(rs1) << " + " << hex::to_hex0x32(imm_i) << ")) = " << hex::to_hex0x32(val);
		}
		regs.set(rd, val);
		pc += 4;
	}
}
void rv32i_hart::exec_stype(uint32_t insn, string mnemonic, ostream* pos) {
	if(mnemonic == "sb") {
		int32_t imm_s = get_imm_s(insn);
		int rs1 = regs.get(get_rs1(insn));
		int32_t addr = rs1 + imm_s;
		int32_t rs2 = regs.get(get_rs2(insn)) & 0b11111111;

		if(pos) {
			string s = render_stype(insn, "sb");
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << "m8(" << hex::to_hex0x32(rs1) << " + " << hex::to_hex0x32(imm_s) << ") = " << hex::to_hex0x32(rs2);
		} 
		mem.set8(addr, rs2); 
		pc += 4;
	}
	else if(mnemonic == "sh") {
		int32_t imm_s = get_imm_s(insn);
		int rs1 = regs.get(get_rs1(insn));
		int32_t addr = rs1 + imm_s;
		int32_t rs2 = regs.get(get_rs2(insn)) & 0b1111111111111111;
		if(pos) {
			string s = render_stype(insn, "sh");
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << "m16(" << hex::to_hex0x32(rs1) << " + " << hex::to_hex0x32(imm_s) << ") = " << hex::to_hex0x32(rs2);
		} 
		mem.set16(addr, rs2); 
		pc += 4;
	}

	else if(mnemonic == "sw") {
		int32_t imm_s = get_imm_s(insn);
		int32_t rs1 = regs.get(get_rs1(insn));
		int32_t addr = rs1 + imm_s;
		int32_t rs2 = regs.get(get_rs2(insn)) & 0b11111111111111111111111111111111;
		if(pos) {
			string s = render_stype(insn, "sw");
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << "m32(" << hex::to_hex0x32(rs1) << " + " << hex::to_hex0x32(imm_s) << ") = " << hex::to_hex0x32(rs2);
		} 
		mem.set32(addr, rs2); 
		pc += 4;
	}
}
void rv32i_hart::exec_itype_alu(uint32_t insn, string mnemonic, int32_t imm_i, ostream* pos) {
	if(mnemonic == "addi") {
		uint32_t rd = get_rd(insn);
		int rs1 = regs.get(get_rs1(insn));
		int32_t val = rs1 + imm_i;

		if(pos) {
			string s = render_itype_alu(insn, "addi", imm_i);
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(rs1) << " + " << hex::to_hex0x32(imm_i) << " = " << hex::to_hex0x32(val);
		} 
		regs.set(rd, val); 
		pc += 4;
	}

	else if(mnemonic == "slti") {
		uint32_t rd = get_rd(insn);
		int rs1 = regs.get(get_rs1(insn));
		int32_t val = (rs1 < imm_i) ? 1 : 0;

		if(pos) {
			string s = render_itype_alu(insn, "slti", imm_i);
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << render_reg(rd) << " = (" << hex::to_hex0x32(rs1) << " < " << imm_i << ") ? 1 : 0 = " << hex::to_hex0x32(val);
		} 
		regs.set(rd, val); 
		pc += 4;
	}

	else if(mnemonic == "sltiu") {
		uint32_t rd = get_rd(insn);
		int rs1 = regs.get(get_rs1(insn));
		int32_t val = ((uint32_t)rs1 < (uint32_t)imm_i) ? 1 : 0;

		if(pos) {
			string s = render_itype_alu(insn, "sltiu", imm_i);
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << render_reg(rd) << " = (" << hex::to_hex0x32(rs1) << " <U " << imm_i << ") ? 1 : 0 = " << hex::to_hex0x32(val);
		} 
		regs.set(rd, val); 
		pc += 4;
	}

	else if(mnemonic == "xori") {
		uint32_t rd = get_rd(insn);
		int rs1 = regs.get(get_rs1(insn));
		int32_t val = rs1 ^ imm_i;

		if(pos) {
			string s = render_itype_alu(insn, "xori", imm_i);
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(rs1) << " ^ " << hex::to_hex0x32(imm_i) << " = " << hex::to_hex0x32(val);
		} 
		regs.set(rd, val); 
		pc += 4;
	}

	else if(mnemonic == "ori") {
		uint32_t rd = get_rd(insn);
		int rs1 = regs.get(get_rs1(insn));
		int32_t val = rs1 | imm_i;

		if(pos) {
			string s = render_itype_alu(insn, "ori", imm_i);
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(rs1) << " | " << hex::to_hex0x32(imm_i) << " = " << hex::to_hex0x32(val);
		} 
		regs.set(rd, val); 
		pc += 4;
	}

	else if(mnemonic == "ori") {
		uint32_t rd = get_rd(insn);
		int rs1 = regs.get(get_rs1(insn));
		int32_t val = rs1 | imm_i;

		if(pos) {
			string s = render_itype_alu(insn, "ori", imm_i);
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(rs1) << " | " << hex::to_hex0x32(imm_i) << " = " << hex::to_hex0x32(val);
		} 
		regs.set(rd, val); 
		pc += 4;
	}
	else if(mnemonic == "andi") {
		uint32_t rd = get_rd(insn);
		int rs1 = regs.get(get_rs1(insn));
		int32_t val = rs1 & imm_i;

		if(pos) {
			string s = render_itype_alu(insn, "andi", imm_i);
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(rs1) << " & " << hex::to_hex0x32(imm_i) << " = " << hex::to_hex0x32(val);
		} 
		regs.set(rd, val); 
		pc += 4;
	}
	else if(mnemonic == "slli") {
		uint32_t rd = get_rd(insn);
		int rs1 = regs.get(get_rs1(insn));
		int32_t val = rs1 << imm_i;

		if(pos) {
			string s = render_itype_alu(insn, "slli", imm_i);
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(rs1) << " << " << imm_i << " = " << hex::to_hex0x32(val);
		} 
		regs.set(rd, val); 
		pc += 4;
	}
	else if(mnemonic == "srli") {
		uint32_t rd = get_rd(insn);
		uint32_t rs1 = regs.get(get_rs1(insn));
		uint32_t shamt_i = get_imm_i(insn)%XLEN;		
		uint32_t val = (rs1 >> shamt_i);

		if(pos) { 
			string s = render_itype_alu(insn, "srli", imm_i);
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(rs1) << " >> " << shamt_i << " = " << hex::to_hex0x32(val);
		} 
		regs.set(rd, val); 
		pc += 4;
	}
	else if(mnemonic == "srai") {
		uint32_t rd = get_rd(insn);
		int rs1 = regs.get(get_rs1(insn));
		int32_t shamt_i = get_imm_i(insn)%XLEN;
		int32_t val = rs1 >> shamt_i;

		if(pos) {
			string s = render_itype_alu(insn, "srai", imm_i);
			*pos << setw(instruction_width) << setfill(' ') << left << s;
			*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(rs1) << " >> " << shamt_i << " = " << hex::to_hex0x32(val);
		} 
		regs.set(rd, val); 
		pc += 4;
	}
}

void rv32i_hart::exec_rtype(uint32_t insn, string mnemonic, ostream* pos) {
	if (mnemonic == "add") 
	{
		uint32_t rd = get_rd (insn);
		uint32_t rs1 = get_rs1 (insn) ;
		uint32_t rs2 = get_rs2 (insn) ;
		int32_t val = (regs.get(rs1) + regs.get(rs2));

		if (pos)
		{
			string s = render_rtype ( insn , "add") ;
			*pos << setw (instruction_width) << setfill (' ') << left << s;
			*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(regs.get(rs1)) << " + " << hex::to_hex0x32(regs.get(rs2)) << " = " << hex::to_hex0x32(val);
		}
		regs.set(rd, val);
		pc += 4;
	}

	else if (mnemonic == "sub") 
	{
		uint32_t rd = get_rd (insn);
		uint32_t rs1 = get_rs1 (insn) ;
		uint32_t rs2 = get_rs2 (insn) ;
		int32_t val = (regs.get(rs1) - regs.get(rs2));

		if (pos)
		{
			string s = render_rtype ( insn , "sub") ;
			*pos << setw (instruction_width) << setfill (' ') << left << s;
			*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(regs.get(rs1)) << " - " << hex::to_hex0x32(regs.get(rs2)) << " = " << hex::to_hex0x32(val);
		}
		regs.set(rd, val);
		pc += 4;
	}

	else if (mnemonic == "sll") 
	{
		uint32_t rd = get_rd (insn);
		uint32_t rs1 = get_rs1 (insn) ;
		uint32_t rs2 = get_rs2 (insn) ;
		int32_t val = (regs.get(rs1) << (regs.get(rs2)%XLEN));

		if (pos)
		{
			string s = render_rtype ( insn , "sll") ;
			*pos << setw (instruction_width) << setfill (' ') << left << s;
			*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(regs.get(rs1)) << " << " << regs.get(rs2)%XLEN << " = " << hex::to_hex0x32(val);
		}
		regs.set(rd, val);
		pc += 4;
	}
	
	else if (mnemonic == "sra") 
	{
		uint32_t rd = get_rd (insn);
		uint32_t rs1 = get_rs1 (insn) ;
		uint32_t rs2 = get_rs2 (insn) ;
		uint32_t val = (regs.get(rs1) >> (regs.get(rs2)%XLEN));

		if (pos)
		{
			string s = render_rtype ( insn , "sra") ;
			*pos << setw (instruction_width) << setfill (' ') << left << s;
			*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(regs.get(rs1)) << " >> " << regs.get(rs2)%XLEN << " = " << hex::to_hex0x32(val);
		}
		regs.set(rd, val);
		pc += 4;
	}

	else if (mnemonic == "srl") 
	{
		int32_t rd = get_rd (insn);
		int32_t rs1 = get_rs1 (insn) ;
		int32_t rs2 = get_rs2 (insn) ;
		uint32_t val = ((uint32_t)regs.get(rs1) >> ((uint32_t)regs.get(rs2)%XLEN));

		if (pos)
		{
			string s = render_rtype ( insn , "srl") ;
			*pos << setw (instruction_width) << setfill (' ') << left << s;
			*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(regs.get(rs1)) << " >> " << regs.get(rs2)%XLEN << " = " << hex::to_hex0x32(val);
		}
		regs.set(rd, val);
		pc += 4;
	}

	else if (mnemonic == "slt") 
	{
		uint32_t rd = get_rd (insn);
		uint32_t rs1 = get_rs1 (insn) ;
		uint32_t rs2 = get_rs2 (insn) ;
		int32_t val = (regs.get(rs1) < regs.get(rs2)) ? 1 : 0;

		if (pos)
		{
			string s = render_rtype ( insn , "slt") ;
			*pos << setw (instruction_width) << setfill (' ') << left << s;
			*pos << "// " << render_reg(rd) << " = (" << hex::to_hex0x32(regs.get(rs1)) << " < " << hex::to_hex0x32(regs.get(rs2)) << ") ? 1 : 0 = " << hex::to_hex0x32(val);
		}
		regs.set(rd, val);
		pc += 4;
	}

	else if (mnemonic == "sltu") 
	{
		uint32_t rd = get_rd (insn);
		uint32_t rs1 = get_rs1 (insn) ;
		uint32_t rs2 = get_rs2 (insn) ;
		int32_t val = ((uint32_t)regs.get(rs1) < (uint32_t)regs.get(rs2)) ? 1 : 0;

		if (pos)
		{
			string s = render_rtype ( insn , "sltu") ;
			*pos << setw (instruction_width) << setfill (' ') << left << s;
			*pos << "// " << render_reg(rd) << " = (" << hex::to_hex0x32(regs.get(rs1)) << " <U " << hex::to_hex0x32(regs.get(rs2)) << ") ? 1 : 0 = " << hex::to_hex0x32(val);
		}
		regs.set(rd, val);
		pc += 4;
	}
	
	else if (mnemonic == "xor") 
	{
		uint32_t rd = get_rd (insn);
		uint32_t rs1 = get_rs1 (insn) ;
		uint32_t rs2 = get_rs2 (insn) ;
		int32_t val = (regs.get(rs1) ^ regs.get(rs2));

		if (pos)
		{
			string s = render_rtype ( insn , "xor") ;
			*pos << setw (instruction_width) << setfill (' ') << left << s;
			*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(regs.get(rs1)) << " ^ " << hex::to_hex0x32(regs.get(rs2)) << " = " << hex::to_hex0x32(val);
		}
		regs.set(rd, val);
		pc += 4;
	}

	else if (mnemonic == "or") 
	{
		uint32_t rd = get_rd (insn);
		uint32_t rs1 = get_rs1 (insn) ;
		uint32_t rs2 = get_rs2 (insn) ;
		int32_t val = (regs.get(rs1) | regs.get(rs2));

		if (pos)
		{
			string s = render_rtype ( insn , "or") ;
			*pos << setw (instruction_width) << setfill (' ') << left << s;
			*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(regs.get(rs1)) << " | " << hex::to_hex0x32(regs.get(rs2)) << " = " << hex::to_hex0x32(val);
		}
		regs.set(rd, val);
		pc += 4;
	}

	else if (mnemonic == "and") 
	{
		uint32_t rd = get_rd (insn);
		uint32_t rs1 = get_rs1 (insn) ;
		uint32_t rs2 = get_rs2 (insn) ;
		int32_t val = (regs.get(rs1) & regs.get(rs2));

		if (pos)
		{
			string s = render_rtype ( insn , "and") ;
			*pos << setw (instruction_width) << setfill (' ') << left << s;
			*pos << "// " << render_reg(rd) << " = " << hex::to_hex0x32(regs.get(rs1)) << " & " << hex::to_hex0x32(regs.get(rs2)) << " = " << hex::to_hex0x32(val);
		}
		regs.set(rd, val);
		pc += 4;
	}
}
void rv32i_hart::exec_csrrs(uint32_t insn, std::ostream* pos) {
	uint32_t rd = get_rd(insn);
	uint32_t rs1 = get_rs1(insn);
	int32_t csr = get_imm_i(insn) & 0x00000fff;;

	if (csr != 0xf14 || rs1 != 0)
	{
		halt = true;
		halt_reason = "Illegal CSR in CRRSS instruction";
	}

	if (pos)
	{
		std::string s = render_csrrx(insn, "csrrs");
		s.resize(instruction_width, ' ');
		*pos << s << "// " << render_reg(rd) << " = " << std::dec << mhartid;
	}
	if (!halt)
	{
		regs.set(rd, mhartid);
		pc += 4;
	}
}

void rv32i_hart::exec_ebreak(uint32_t insn, ostream*pos) {
	if(pos) {
		string s = render_ebreak ( insn );
		*pos << std :: setw ( instruction_width ) << std :: setfill (' ') << std :: left << s;
		*pos << "// HALT";
	}
	halt = true ;
	halt_reason = "EBREAK instruction";
}

void rv32i_hart::tick ( const std :: string & hdr) {
	if(is_halted() == true) 
		return;
	else {
		insn_counter++;
		if(show_registers == true) {
			dump(); //calls dump (below)
		}
		uint32_t insn = mem.get32(pc); //fetched instructions (hex)
		if(show_instructions == true) {
			cout << hdr << hex::to_hex32(pc) << ": " << hex::to_hex32(insn); 
			exec(insn, &cout);
			cout <<	endl;
		}
		else
			exec(insn, nullptr);
	}
}

void rv32i_hart::dump (const string & hdr) const {

	regs.dump(hdr);
	cout << " pc " << hex::to_hex32(pc) << endl;
}

void rv32i_hart::reset () {
	pc = 0;
	regs.reset();
	insn_counter = 0;
	halt = false;
	halt_reason = "none";
}
