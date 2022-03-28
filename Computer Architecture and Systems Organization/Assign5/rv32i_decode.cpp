//**************************************************************
//
// CSCI 463 Assignment 5
//
// Author: Harry Chieng
//
// rv32i_decode.cpp
//
//**************************************************************

#include "hex.h"
#include "memory.h"
#include "rv32i_decode.h"
#include <string>
#include <sstream>
#include <iomanip>

using std::string;
using std::ostringstream;
using std::setw;
using std::left;


string rv32i_decode::decode(uint32_t addr, uint32_t insn) {
	switch(get_opcode(insn))
	{
		default: return render_illegal_insn(insn);
		case opcode_lui: return render_lui(insn);
		case opcode_auipc: return render_auipc(insn);
		case opcode_jal: return render_jal(addr, insn);
		case opcode_jalr: return render_jalr(insn);
		case opcode_btype:
				  switch (get_funct3(insn))
				  {
					  default: return render_illegal_insn(insn);
					  case funct3_beq: return render_btype(addr, insn, "beq");
					  case funct3_bne: return render_btype(addr, insn, "bne");
					  case funct3_blt: return render_btype(addr, insn, "blt");
					  case funct3_bge: return render_btype(addr, insn, "bge");
					  case funct3_bltu: return render_btype(addr, insn, "bltu");
					  case funct3_bgeu: return render_btype(addr, insn, "bgeu");
				  }
		case opcode_load_imm: 
				  switch (get_funct3(insn)) {
					  default: return render_illegal_insn(insn);
					  case funct3_lb: return render_itype_load(insn, "lb");
					  case funct3_lh: return render_itype_load(insn, "lh");
					  case funct3_lw: return render_itype_load(insn, "lw");
					  case funct3_lbu: return render_itype_load(insn, "lbu");
					  case funct3_lhu: return render_itype_load(insn, "lhu");
				  }
		case opcode_stype: 
				  switch (get_funct3(insn)) {
					  default: return render_illegal_insn(insn);
					  case funct3_sb: return render_stype(insn, "sb");
					  case funct3_sh: return render_stype(insn, "sh");
					  case funct3_sw: return render_stype(insn, "sw");
				  }
		case opcode_alu_imm:
				  switch (get_funct3(insn))
				  {
					  default: return render_illegal_insn(insn);
					  case funct3_add: return render_itype_alu(insn, "addi", get_imm_i(insn));
					  case funct3_slt: return render_itype_alu(insn, "slti", get_imm_i(insn));
					  case funct3_sltu: return render_itype_alu(insn, "sltiu", get_imm_i(insn));
					  case funct3_xor: return render_itype_alu(insn, "xori", get_imm_i(insn));
					  case funct3_or: return render_itype_alu(insn, "ori", get_imm_i(insn));
					  case funct3_and: return render_itype_alu(insn, "andi", get_imm_i(insn));

					  case funct3_sll: return render_itype_alu(insn, "slli", get_imm_i(insn)%XLEN);
					  case funct3_srx: 
							   switch(get_funct7(insn))
							   {
								   default: return render_illegal_insn(insn);
								   case funct7_sra: return render_itype_alu(insn, "srai", get_imm_i(insn)%XLEN);
								   case funct7_srl: return render_itype_alu(insn, "srli", get_imm_i(insn)%XLEN);
							   }
				  }
		case opcode_rtype: 
				  switch (get_funct3(insn)) {
					  default: return render_illegal_insn(insn);
					  case funct3_add: 
						   switch(get_funct7(insn)) {
							   default: return render_illegal_insn(insn);
							   case funct7_add: return render_rtype(insn, "add");
							   case funct7_sub: return render_rtype(insn, "sub");
						   }
					  case funct3_sll: return render_rtype(insn, "sll");
					  case funct3_srx: 
							   switch(get_funct7(insn))
							   {
								   default: return render_illegal_insn(insn);
								   case funct7_sra: return render_rtype(insn, "sra");
								   case funct7_srl: return render_rtype(insn, "srl");
							   }
					  case funct3_slt: return render_rtype(insn, "slt");
					  case funct3_sltu: return render_rtype(insn, "sltu");
					  case funct3_xor: return render_rtype(insn, "xor");
					  case funct3_or: return render_rtype(insn, "or");
					  case funct3_and: return render_rtype(insn, "and");

				  }
		case opcode_system:
				  if (insn == insn_ecall)
					  return render_ecall(insn);
				  if (insn == insn_ebreak)
					  return render_ebreak(insn);
				  switch (get_funct3(insn)) {
					  default: return render_illegal_insn(insn);
					  case funct3_csrrw: return render_csrrx(insn, "csrrw");
					  case funct3_csrrs: return render_csrrx(insn, "csrrs");
					  case funct3_csrrc: return render_csrrx(insn, "csrrc");
					  case funct3_csrrwi: return render_csrrxi(insn, "csrrwi");
					  case funct3_csrrsi: return render_csrrxi(insn, "csrrsi");
					  case funct3_csrrci: return render_csrrxi(insn, "csrrci");	   
				  }
	}
}

string rv32i_decode::render_illegal_insn(uint32_t) {
	//uint32_t insn = 
	ostringstream os;
	os << "  ERROR: UNIMPLEMENTED INSTRUCTION";
	return os.str();
}

string rv32i_decode::render_lui(uint32_t insn) {
	uint32_t rd = get_rd(insn);
	int32_t imm_u = get_imm_u(insn);
	ostringstream os;
	os << render_mnemonic("lui") << render_reg(rd) << "," << hex::to_hex0x20((imm_u >> 12)&0x0fffff);
	return os.str();
}

string rv32i_decode::render_auipc(uint32_t insn) {
	uint32_t rd = get_rd(insn);
	int32_t imm_u = get_imm_u(insn);
	ostringstream os;
	os << render_mnemonic("auipc") << render_reg(rd) << "," << hex::to_hex0x20((imm_u >> 12)&0x0fffff);
	return os.str();
}

string rv32i_decode::render_jal(uint32_t addr, uint32_t insn) {
	uint32_t rd = get_rd(insn);
	int32_t imm_j = get_imm_j(insn);
	int pcrel_21 = addr + imm_j;  //pc = program counter (addr), imm = immediate
	ostringstream os;
	os << render_mnemonic("jal") << render_reg(rd) << "," << hex::to_hex0x32(pcrel_21);
	return os.str();
}

string rv32i_decode::render_jalr (uint32_t insn) {
	uint32_t rd = get_rd(insn);
	int32_t imm_i = get_imm_i(insn);
	int rs1 = get_rs1(insn);
	ostringstream os;
	os << render_mnemonic("jalr") << render_reg(rd) << "," << render_base_disp(rs1, imm_i);
	return os.str();
}

string rv32i_decode::render_btype(uint32_t addr, uint32_t insn, const char *mnemonic) {
	int32_t imm_b = get_imm_b(insn);
	int pcrel_13 = addr + imm_b;
	int rs1 = get_rs1(insn);
	int rs2 = get_rs2(insn);

	ostringstream os;
	os << render_mnemonic(mnemonic) << render_reg(rs1) << "," << render_reg(rs2) << "," << hex::to_hex0x32(pcrel_13);
	return os.str();
}

string rv32i_decode::render_itype_load(uint32_t insn, const char *mnemonic) {
	uint32_t rd = get_rd(insn);
	int32_t imm_i = get_imm_i(insn);
	int rs1 = get_rs1(insn);
	ostringstream os;
	os << render_mnemonic(mnemonic) << render_reg(rd) << "," << render_base_disp(rs1, imm_i); 
	return os.str();
}

string rv32i_decode::render_stype(uint32_t insn, const char *mnemonic) {
	int32_t imm_s = get_imm_s(insn);
	int rs1 = get_rs1(insn);
	int rs2 = get_rs2(insn);
	ostringstream os;
	os << render_mnemonic(mnemonic) << render_reg(rs2) << "," << render_base_disp(rs1, imm_s);
	return os.str();
}

string rv32i_decode::render_itype_alu(uint32_t insn, const char *mnemonic, int32_t imm_i) {
	uint32_t rd = get_rd(insn);
	int rs1 = get_rs1(insn);
	ostringstream os;
	os << render_mnemonic(mnemonic) << render_reg(rd) << "," << render_reg(rs1) << "," << imm_i;
	return os.str();
}

string rv32i_decode::render_rtype(uint32_t insn, const char *mnemonic) {
	uint32_t rd = get_rd(insn);
	int rs1 = get_rs1(insn);
	int rs2 = get_rs2(insn);
	ostringstream os;
	os << render_mnemonic(mnemonic) << render_reg(rd) << "," << render_reg(rs1) << "," << render_reg(rs2);
	return os.str();
}

string rv32i_decode::render_ecall(uint32_t) {
	ostringstream os;
	os << render_mnemonic("ecall"); 
	return os.str();
}

string rv32i_decode::render_ebreak(uint32_t) {
	ostringstream os;
	os << render_mnemonic("ebreak");
	return os.str();
}

string rv32i_decode::render_csrrx(uint32_t insn, const char *mnemonic) {
	uint32_t rd = get_rd(insn);
	ostringstream os;
	int rs1 = get_rs1(insn);
	uint16_t csr = get_imm_i(insn) & 0xFFF;
	os << render_mnemonic(mnemonic) << render_reg(rd) << "," << hex::to_hex0x12(csr) << "," << render_reg(rs1);
	return os.str();
}

string rv32i_decode::render_csrrxi(uint32_t insn, const char *mnemonic) {
	uint32_t rd = get_rd(insn);
	ostringstream os;
	int zimm = get_rs1(insn);
	uint16_t csr = get_imm_i(insn) & 0xFFF;
	os << render_mnemonic(mnemonic) << render_reg(rd) << "," << hex::to_hex0x12(csr) << "," << zimm;
	return os.str();
}

// These 3 functions are also helper-functions to eliminate further messy replicated code.
string rv32i_decode::render_reg(int r) {
	ostringstream os;
	os << "x" << r;
	return os.str();
}
//this func is the one and only way that any code may formay an imm(register) operand in the app.
string rv32i_decode::render_base_disp(uint32_t reg, int32_t imm) {
	ostringstream os;
	os << imm << "(" << render_reg(reg) << ")";
	return os.str();
}
string rv32i_decode::render_mnemonic(const string &mnemonic) {
	//this is supposed to make space padding on the right side "setw?" by mnemonic_width char long. When was mnemonic_width specified?
	//int mnemonic_width;
	ostringstream os;
	if(mnemonic == "ecall" || mnemonic == "ebreak") {
		os << "  " << mnemonic;
	}
	else {
		os << "  " << left << setw(mnemonic_width) << mnemonic;
	}
	return os.str();
}

//can add more of the given functions (above) if needed

//helper-functions for extracting the fields from an instruction (instruction decoding logic) will be easier to write, debug and understand.

uint32_t rv32i_decode::get_opcode(uint32_t insn) {
	return (insn & 0b00000000000000000000000001111111); //would we need the extra 0s?
}

uint32_t rv32i_decode::get_rd(uint32_t insn) {
	return (insn & 0b00000000000000000000111110000000) >> 7;
}

uint32_t rv32i_decode::get_funct3(uint32_t insn) {
	return (insn & 0b00000000000000000111000000000000) >> 12;
}

uint32_t rv32i_decode::get_rs1(uint32_t insn) {
	return (insn & 0b00000000000011111000000000000000) >> 15;
}

uint32_t rv32i_decode::get_rs2(uint32_t insn) {
	return (insn & 0b00000001111100000000000000000000) >> 20;
}

uint32_t rv32i_decode::get_funct7(uint32_t insn) {
	return (insn & 0b11111110000000000000000000000000) >> 25;
}

int32_t rv32i_decode::get_imm_i(uint32_t insn) {
	uint32_t imm_i = (insn & 0b11111111111100000000000000000000) >> 20;
	if (insn & 0b10000000000000000000000000000000)
		imm_i |= 0b11111111111111111111000000000000;
	return imm_i;
}

int32_t rv32i_decode::get_imm_u(uint32_t insn) {
	uint32_t imm_u = (insn & 0b11111111111111111111000000000000);
	return imm_u;

}

int32_t rv32i_decode::get_imm_b(uint32_t insn) {
	int32_t imm_b = (insn & 0b01111110000000000000000000000000) >> (25-5);
	imm_b |= (insn & 0b00000000000000000000111100000000) >> (8-1);
	imm_b |= (insn & 0b10000000000000000000000000000000) >> (31-12);
	imm_b |= (insn & 0b00000000000000000000000010000000) << (11-7);

	if (insn & 0x80000000)
		imm_b |= 0xffffe000; //sign-extend the left reference in RISC-V

	return imm_b;
}

int32_t rv32i_decode::get_imm_s(uint32_t insn) {
	int32_t imm_s = (insn & 0xfe000000) >> (25-5);
	imm_s |= (insn & 0x00000f80) >> (7-0);

	if (insn & 0x80000000)
		imm_s |= 0xfffff000; //sign-extend the left reference page 55 in RISC-V

	return imm_s;
}

int32_t rv32i_decode::get_imm_j(uint32_t insn) {
	int32_t imm_j = (insn & 0b10000000000000000000000000000000) >> (31-20);
	imm_j |= (insn & 0b01111111111000000000000000000000) >> (21-1);
	imm_j |= (insn & 0b00000000000100000000000000000000) >> (20-11);
	imm_j |= (insn & 0b00000000000011111111000000000000) >> (12-12);

	if (insn & 0b10000000000000000000000000000000)
		imm_j |= 0b11111111111000000000000000000000; //sign-extend the left reference page 49 in RISC-V

	return imm_j;
}
