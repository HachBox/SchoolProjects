/*
 * CSCI 463 - Assignment 5
 *
 * Author: Harry Chieng
 *
 * RISC-V Simulator - rv32i_hart.h 
 *
 ******************************************/

#ifndef rv32i_hart_h
#define rv32i_hart_h

#include "hex.h"
#include "rv32i_decode.h"
#include "memory.h"
#include "registerfile.h"

using std::ostream;

class rv32i_hart : public rv32i_decode
{
	public :
		/*
		 * This is the rv32i_hart's constructor
		 *
		 * @param mem for memory
		 *
		 *******************************************************************/
		rv32i_hart ( memory&m) : mem ( m) { }

		/*
		 * This shows the instructions from the private member.
		 *
		 * @param b is a boolean value.
		 *
		 * ****************************************************************/
		void set_show_instructions ( bool b) { show_instructions = b ; }

		/*
		 * This function shows the registers from the private member. When true,
		 * dump the registers before instructions is executed.
		 *
		 * @param b is a boolean value.
		 *
		 ******************************************************************/
		void set_show_registers ( bool b) { show_registers = b; }

		/*
		 * Accessor for halt.
		 *
		 * @return return true if the hard has been halted for any reason.
		 *
		 ******************************************************************/
		bool is_halted () const { return halt ; }

		/*
		 * Returns a string iundicating the reason the hart has been halted.
		 *
		 * @return halt_reason returns the reason of the halt.
		 *
		 * ****************************************************************/
		const std :: string & get_halt_reason () const { return halt_reason ; }

		/*
		 * Accessor for insn_counter. Returns the number of instructions that 
		 * have been executed by the simulator.
		 *
		 * @return insn_counter returns the instruction counter.
		 *
		 * ****************************************************************/
		uint64_t get_insn_counter () const { return insn_counter ; }

		/*
		 * Mutator for mHartID, used to set the ID value to be returned by the 
		 * csrrs instruction for CSR register.
		 *
		 * @param i a regular integer
		 *
		 * ****************************************************************/
		void set_mhartid ( int i ) { mhartid = i; }

		/*
		 * The tick() method function is how to tell the sumlatror to execute 
		 * and instruction.
		 *
		 * @param hdr The hdr parameter is required to be printed on the left
		 * of any and all output that is displayed as a result of calling 
		 * this method.
		 *
		 * ****************************************************************/
		void tick ( const std :: string & hdr ="") ;

		/*
		 * Dump the entire stat of the hart.
		 *
		 * @param hdr The hdr parameter is required to be printed on the left
		 * of any and all output that is displayed as a result of calling 
		 * this method.
		 *
		 * *****************************************************************/
		void dump ( const std :: string & hdr ="") const ;

		/*
		 * Reset the rv32i object and the register file.
		 *
		 * @note different than the reset in cpu register.
		 *
		 * ****************************************************************/
		void reset () ;

	private :
		static constexpr int instruction_width = 37; //this is 35
		
		/*
		 * The exec function executes the given rv32i instruction by making
		 * use of the get_xxx() methods to extract the needed instruction fields.
		 *
		 * @param insn this is the instruction that controls the given pos
		 *
		 * @param pos this is the output stream
		 *
		 * ******************************************************************/
		void exec ( uint32_t insn , ostream *);

		/*
		 * The exec illegal instruction function flagts if the ostream paramter
		 * is not nullptr. 
		 *
		 * @param insn this is the instruction that controls the given pos
		 *
		 * @param pos this is the output stream
		 *
		 * ********************************************************************/
		void exec_illegal_insn ( uint32_t insn , ostream *);

		/*
		 * The exec add upper immediate to PC loads and address relative to the 
		 * current PC.
		 *
		 * @param insn this is the instruction that controls the given pos
		 *
		 * @param pos this is the output stream
		 *
		 * **********************************************************************/
		void exec_auipc (uint32_t insn, ostream* pos);

		/*
		 * the load upper immediate includes a conditional addition of 1 to the
		 * operand.
		 *
		 * @param insn this is the instruction that controls the given pos
		 *
		 * @param pos this is the output stream
		 *
		 * **********************************************************************/
		void exec_lui (uint32_t insn, ostream* pos);

		/*
		 * Introduce and present subroutines but not nesting until introduce stack
		 * operations.
		 *
		 * @param insn this is the instruction that controls the given pos
		 *
		 * @param pos this is the output stream
		 *
		 * **********************************************************************/
		void exec_jal (uint32_t insn, ostream* pos);

		/*
		 * introduces and present subroutines but not nesting until introduce stack
		 * operations.
		 *
		 * @param insn this is the instruction that controls the given pos
		 *
		 * @param pos this is the output stream
		 *
		 * ***********************************************************************/
		void exec_jalr(uint32_t insn, ostream* pos);

		/*
		 * Covered inside the itype_alu function.
		 *
		 * **************************************************************************/
		void exec_slt ( uint32_t insn , ostream * pos );

		/*
		 * The b-type instruction format is used for branch instructions.
		 *
		 * @param insn this is the instruction that controls the given pos
		 *
		 * @param pos this is the output stream
		 *
		 * **************************************************************************/
		void exec_btype (uint32_t insn, ostream* pos, string mnemonic);	

		/*
		 * The I-type instruction format is used to encode instructions with a signed
		 * 12-bit immediate operand.
		 *
		 * @param insn this is the instruction that controls the given pos
		 *
		 * @param pos this is the output stream
		 *
		 *****************************************************************************/
		void exec_itype_load(uint32_t insn, string mnemonic, ostream* pos);

		/*
		 * The S-type instruction format is used to encode instructions with a signed 12-bit 
		 * immediate operand.
		 *
		 * @param insn this is the instruction that controls the given pos
		 *
		 * @param pos this is the output stream
		 *
		 * ****************************************************************************/
		void exec_stype(uint32_t insn, string mnemonic, ostream* pos);

		/*
		 * The I-type instruction format is used to encode instructions.
		 *
		 * @param insn this is the instruction that controls the given pos
		 *
		 * @param pos this is the output stream
		 *
		 * **************************************************************************/
		void exec_itype_alu(uint32_t insn, string mnemonic, int32_t imm_i, ostream* pos);

		/*
		 * The R-type instructions are used for operations that set a destination register
		 *
		 * @param insn this is the instruction that controls the given pos
		 *
		 * @param pos this is the output stream
		 *
		 * @param imm_i the function used for imm_i is the same, but given as a paramter.
		 *
		 * **************************************************************************/
		void exec_rtype(uint32_t insn, string mnemonic, ostream* pos);

		/*
		 * generates breakpoint exceptions
		 *
		 * @param insn this is the instruction that controls the given pos
		 *
		 * @param pos this is the output stream
		 *
		 * ****************************************************************************/
		void exec_ebreak(uint32_t insn, ostream* pos);

		/*
		 * The csrrs function reads the old value of the CSR.
		 *
		 * @param insn this is the instruction that controls the given pos
		 *
		 * @param pos this is the output stream
		 *
		 * ***************************************************************************/
		void exec_csrrs (uint32_t insn, ostream* pos);

		bool halt = { false };
		std :: string halt_reason = { " none " };
		uint32_t mhartid = {0};
		bool show_instructions;
		bool show_registers;
		uint64_t insn_counter = { 0 };
		uint32_t pc = { 0 };

	protected :
		registerfile regs ;
		memory &mem;
};

#endif
