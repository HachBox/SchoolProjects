/*
 * CSCI 463 Assignment 4
 *
 * Author: Harry Chieng
 *
 * rv32i_decode.h
 *
 ***************************************************/

#ifndef rv32i_decode_h
#define rv32i_decode_h

class rv32i_decode : public hex
{
	public:

/**
 * It is the purpose of this function to return a std::string containing 
 * the disassembled instruction text.
 *
 * For each case, call a function to format/render the instruction and its 
 * arguments (when the opcode is specific enough to do so such as for the 
 * lui instruction) or use a sub-switch statement to further decode any 
 * additionally required fields (such as funct3 and/or funct7) and then call 
 * a function to format the instruction.
 *
 * @param addr The memory address where the instructions (insn) is stored is 
 * passed to decode() so that it may be used to calculate the PC-relative target 
 * address shown in the J-type and B-type instructions.
 *
 * @param insn The instruction hex value, not really sure what else I can say.
 *
 * @note The layout of this entire decode function should follow page 80 of the 
 * RISC-V book. Make sure to take account the funct3 of each constant and other
 * essential variables.
 *
 * @warning Ensure that the decode function iterates over all of the constants 
 * and their corresponding counterparts based on the Rv32I Base Instruction Set
 * Encoding table. 
 *
 * ***************************************************************************/
		//@parm addr The memory address where the insn is stored.
		static std::string decode(uint32_t addr, uint32_t insn);

	protected:

		/**
		 *
		 * These are all constants used for the decode function
		 *
		 * ******************************************/
		static constexpr int mnemonic_width             = 8;

		static constexpr uint32_t opcode_lui			= 0b0110111;
		static constexpr uint32_t opcode_auipc			= 0b0010111;
		static constexpr uint32_t opcode_jal			= 0b1101111;
		static constexpr uint32_t opcode_jalr			= 0b1100111;
		static constexpr uint32_t opcode_btype			= 0b1100011;
		static constexpr uint32_t opcode_load_imm		= 0b0000011;
		static constexpr uint32_t opcode_stype			= 0b0100011;
		static constexpr uint32_t opcode_alu_imm		= 0b0010011;
		static constexpr uint32_t opcode_rtype			= 0b0110011;
		static constexpr uint32_t opcode_system			= 0b1110011;

		static constexpr uint32_t funct3_beq			= 0b000;
		static constexpr uint32_t funct3_bne			= 0b001;
		static constexpr uint32_t funct3_blt			= 0b100;
		static constexpr uint32_t funct3_bge			= 0b101;
		static constexpr uint32_t funct3_bltu			= 0b110;
		static constexpr uint32_t funct3_bgeu			= 0b111;

		static constexpr uint32_t funct3_lb				= 0b000;
		static constexpr uint32_t funct3_lh				= 0b001;
		static constexpr uint32_t funct3_lw				= 0b010;
		static constexpr uint32_t funct3_lbu			= 0b100;
		static constexpr uint32_t funct3_lhu			= 0b101;

		static constexpr uint32_t funct3_sb				= 0b000;
		static constexpr uint32_t funct3_sh				= 0b001;
		static constexpr uint32_t funct3_sw				= 0b010;

		static constexpr uint32_t funct3_add			= 0b000;
		static constexpr uint32_t funct3_sll			= 0b001;
		static constexpr uint32_t funct3_slt			= 0b010;
		static constexpr uint32_t funct3_sltu			= 0b011;
		static constexpr uint32_t funct3_xor			= 0b100;
		static constexpr uint32_t funct3_srx			= 0b101;
		static constexpr uint32_t funct3_or				= 0b110;
		static constexpr uint32_t funct3_and			= 0b111;

		static constexpr uint32_t funct7_srl			= 0b0000000;
		static constexpr uint32_t funct7_sra			= 0b0100000;

		static constexpr uint32_t funct7_add			= 0b0000000;
		static constexpr uint32_t funct7_sub			= 0b0100000;

		static constexpr uint32_t insn_ecall			= 0x00000073;
		static constexpr uint32_t insn_ebreak			= 0x00100073;

		static constexpr uint32_t funct3_csrrw			= 0b001;
		static constexpr uint32_t funct3_csrrs			= 0b010;
		static constexpr uint32_t funct3_csrrc			= 0b011;
		static constexpr uint32_t funct3_csrrwi			= 0b101;
		static constexpr uint32_t funct3_csrrsi			= 0b110;
		static constexpr uint32_t funct3_csrrci			= 0b111;

/**
 *
 * Extract and return the opcode field from the given instruction.
 *
 * @param insn The instruction hex value.
 *
 * @return Returns a masked instruction of the corresponding masked
 * area based on the pg 47 of the RISC-V book.
 *
 * *******************************************************/
		static uint32_t get_opcode(uint32_t insn);

/**
 *
 * Extract and return the rd field from the given instruction.
 *
 * @param insn The instruction hex value.
 *
 * @return Returns a masked instruction of the corresponding masked
 * area based on the pg 47 of the RISC-V book shifted 7.
 *
 * *******************************************************/
		static uint32_t get_rd(uint32_t insn);

/**
 * Extract and return the funct3 field from the given instruction
 *
 * @param insn The instruction hex value.
 *
 * @return Returns a masked instruction of the corresponding masked
 * area based on the pg 47 of the RISC-V book shifted 12.
 *
 * *******************************************************/
		static uint32_t get_funct3(uint32_t insn);

/**
 * Extract and return the rs1 field from the given instruction
 *
 * @param insn The instruction hex value.
 *
 * @return Returns a masked instruction of the corresponding masked
 * area based on the pg 47 of the RISC-V book shifted 15.
 *
 * *******************************************************/
		static uint32_t get_rs1(uint32_t insn);

/**
 * Extract and return the rs2 field from the given instruction
 *
 * @param insn The instruction hex value.
 *
 * @return Returns a masked instruction of the corresponding masked
 * area based on the pg 47 of the RISC-V book shifted 20.
 *
 * *******************************************************/
		static uint32_t get_rs2(uint32_t insn);

/**
 * Extract and return the funct7 field from the given instruction
 *
 * @param insn The instruction hex value.
 *
 * @return Returns a masked instruction of the corresponding masked
 * area based on the pg 47 of the RISC-V book shifted 25.
 *
 * *******************************************************/
		static uint32_t get_funct7(uint32_t insn);

/**
 * Extract and return the imm_i field from the given instruction
 * It is split between immediate value of the I-type instruction.
 *
 * @param insn The instruction hex value.
 *
 * @return Returns the masked variable imm_i.
 *
 * *******************************************************/
		static int32_t get_imm_i(uint32_t insn);

/**
 * Extract and return the imm_u field from the given instruction
 *
 * @param insn The instruction hex value.
 * 
 * @return Returns the masked variable imm_u.
 *
 * *******************************************************/
		static int32_t get_imm_u(uint32_t insn);

/**
 * Extract and return the imm_b field from the given instruction
 * It is split between immediate value of the B-type instructions,
 * while checking if the masked areas referenced from the RISC-V 
 * manual corresponds with the shifts.
 *
 * @param insn The instruction hex value.
 * 
 * @return Returns the masked variable imm_b.
 *
 * *******************************************************/
		static int32_t get_imm_b(uint32_t insn);

/**
 * Extract and return the imm_s field from the given instruction
 * It is split between immediate value of the S-type instruction.
 *
 * @param insn The instruction hex value.
 * 
 * @return Returns the masked variable imm_s.
 *
 * *******************************************************/
		static int32_t get_imm_s(uint32_t insn);

/**
 * Extract and return the imm_j field from the given instruction
 * It is split between immediate value of the J-type instructions,
 * while checking if the masked areas referenced from the RISC-V 
 * manual corresponds with the shifts.
 *
 * @param insn The instruction hex value.
 * 
 * @return Returns the masked variable imm_j.
 *
 * *******************************************************/
		static int32_t get_imm_j(uint32_t insn);

		static constexpr uint32_t XLEN = 32;

		/**
		 * The renderer for invalid instructions.
		 *
		 * @param insn The instruction hex value
		 * 
		 * @return Returns a string " ERROR: UNIMPLEMENTED INSTRUCTION"
		 *
		 * ***********************************************************/
		static std::string render_illegal_insn(uint32_t insn);

		/**
		 * The li pseudoinstruction instructions includes a conditional 
		 * addition of 1 to the operand.
		 *
		 * @param insn The instruction hex value.
		 * 
		 * @return Print the memory address, instruction hex value, 
		 * and the instruction mnemonic. 
		 *
		 * ***********************************************************/
		static std::string render_lui(uint32_t insn);

		/**
		 * Loan an address relative to the current PC.
		 * 
		 * @param insn The instruction hex value.
		 * 
		 * @return Print the memory address, instruction hex value, 
		 * and the instruction mnemonic. 
		 *
		 * ***********************************************************/
		static std::string render_auipc(uint32_t insn);

		/**
		 * Introduce and present subroutines but not nesting until 
		 * introduce stack operations.
		 * 
		 * @param insn The instruction hex value.
		 * @parm addr The memory address where the insn is stored.
		 * 
		 * @return Print the memory address, instruction hex value, 
		 * and the instruction mnemonic. 
		 *
		 * ***********************************************************/
		static std::string render_jal(uint32_t addr, uint32_t insn);

		/**
		 * Introduce and present subroutines but not nesting until 
		 * introduce stack operations.
		 * 
		 * @param insn The instruction hex value.
		 * 
		 * @return Print the memory address, instruction hex value, 
		 * and the instruction mnemonic. 
		 *
		 * ***********************************************************/
		static std::string render_jalr(uint32_t insn);

		/**
		 *
		 * The B-type instruction format is used for branch instructions 
		 * that require an even immediate value 1751 that is used to 
		 * determine the branch target address as an offset from the 
		 * current instruction’s address.
		 * 
		 * @param insn The instruction hex value.
		 * @param mnemonic The constant defined from the header file.
		 * @parm addr The memory address where the insn is stored.
		 *
		 * @return Print the memory address, instruction hex value, 
		 * and the instruction mnemonic. 
		 *
		 * ***********************************************************/
		static std::string render_btype(uint32_t addr, uint32_t insn, const char *mnemonic);

		/**
		 * The I-type instruction format is used to encode instructions with 
		 * a signed 12-bit immediate operand with a range of [−2048..2047], 
		 * an rd register, and an rs1 register.
		 * 
		 * @param insn The instruction hex value.
		 * @param mnemonic The constant defined from the header file.		
		 *
		 * @return Print the memory address, instruction hex value, 
		 * and the instruction mnemonic. 
		 *
		 * ***********************************************************/
		static std::string render_itype_load(uint32_t insn, const char *mnemonic);

		/**
		 * The S-type instruction format is used to encode instructions with
		 * a signed 12-bit immediate operand with a range of [−2048..2047], 
		 * an rs1 register, and an rs2 register.
		 *
		 * @param mnemonic The constant defined from the header file.		
		 *
		 * @return Print the memory address, instruction hex value, 
		 * and the instruction mnemonic.
		 *
		 * ***********************************************************/
		static std::string render_stype(uint32_t insn, const char *mnemonic);

		/**
		 * The I-type instruction format is used to encode instructions with 
		 * a signed 12-bit immediate operand with a range of [−2048..2047], 
		 * an rd register, and an rs1 register.
		 * 
		 * @param insn The instruction hex value.
		 * @param mnemonic The constant defined from the header file.	
		 * @param imm_i The imm_i operand 	
		 *
		 * @return Print the memory address, instruction hex value, 
		 * and the instruction mnemonic.
		 *
		 * ***********************************************************/
		static std::string render_itype_alu(uint32_t insn, const char *mnemonic, int32_t imm_i);

		/**
		 * The R-type instructions are used for operations that set a 
		 * destination register rd to the result of an arithmetic, logical 
		 * or shift operation applied to source registers rs1 and rs2.

		 * @param insn The instruction hex value.
		 * @param mnemonic The constant defined from the header file.		
		 *
		 * @return Print the memory address, instruction hex value, 
		 * and the instruction mnemonic. 
		 *
		 * ***********************************************************/
		static std::string render_rtype(uint32_t insn, const char *mnemonic);

		/**
		 * Instruction used for the communication.
		 * 
		 * @param insn The instruction hex value.
		 *
		 * @return Print the memory address, instruction hex value, 
		 * and the instruction mnemonic.
		 *
		 * ***********************************************************/
		static std::string render_ecall(uint32_t insn);

		/**
		 * Generates breakpoint exception.
		 * 
		 * @param insn The instruction hex value.
		 *
		 * @return Print the memory address, instruction hex value, 
		 * and the instruction mnemonic. 
		 *
		 * ***********************************************************/
		static std::string render_ebreak(uint32_t insn);

		/**
		 * CSRRX reads the old value of the CSR, zero-extends the value 
		 * to XLEN bits, then writes it to integer register rd. 
		 * 
		 * @param insn The instruction hex value.
		 * @param mnemonic The constant defined from the header file.		
		 *
		 * @return Print the memory address, instruction hex value, 
		 * and the instruction mnemonic. 
		 *
		 * ***********************************************************/
		static std::string render_csrrx(uint32_t insn, const char *mnemonic);

		/**
		 * Essentially, the same as CSRRX but with limitations
		 * 
		 * @param insn The instruction hex value.
		 * @param mnemonic The constant defined from the header file.		
		 *
		 * @return Print the memory address, instruction hex value, 
		 * and the instruction mnemonic. 
		 *
		 * ***********************************************************/
		static std::string render_csrrxi(uint32_t insn, const char *mnemonic);

		/**
		 * Calling this member is the one and only way that any code may 
		 * format the name of a register into a string (for subsequent 
		 * printing by the program.).
		 * 
		 * @param r r is the given name of the register.
		 *
		 * @return Print the memory address, instruction hex value, 
		 * and the instruction mnemonic. 
		 *
		 * ***********************************************************/
		static std::string render_reg(int r);

		/**
		 * Use this to render, into a std::string, the operatnds of the 
		 * form imm(register) for those instructions that have such an 
		 * addressing mode.
		 *
		 * @param base Rendered into a string
		 *  
		 * @param disp Printed in decimal
		 *
		 * @return Print the memory address, instruction hex value, 
		 * and the instruction mnemonic. 
		 *
		 * ***********************************************************/
		static std::string render_base_disp(uint32_t base, int32_t disp);

		/**
		 * Render, into a std::string, the given instruction mnemonic 
		 * with the proper space padding on right side to make it 
		 * mnemonic_width characters long. Also checks if the given
		 * data is given the mnemonic ecall or ebreak and just returns it.
		 * 
		 * @param m The constant defined from the header file.		
		 *
		 * @return Print the memory address, instruction hex value, 
		 * and the instruction mnemonic. 
		 *
		 * ***********************************************************/
		static std::string render_mnemonic(const std::string &m);
};

#endif
