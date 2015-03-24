/*
	$ [KiPHP] /r5/output_handler.h  (1406)    (C) 2005-2014  MF
*/


#if KI_RING >= 5

#ifndef _R5_OUTPUT_HANDLER_H_
#define _R5_OUTPUT_HANDLER_H_




class r5_output_handler_code : public r5_output_handler	{
	public:
		virtual	void	callback_begin		(void);
		virtual	void	callback_end		(void);
		virtual	void	callback_code		(r2_code_t);
		virtual	void	callback_function	(r2_class_t, r2_code_t);
};




class r5_output_handler_interlang : public r5_output_handler {
	private:
		const char *	fetch	(r2_code_directive_opcode_e opcode);

		void	operand		(r2_code_directive_operand_t operand, const char *prefix = NULL);


	public:
		virtual	void	callback_begin		(void);
		virtual	void	callback_end		(void);
		virtual	void	callback_code		(r2_code_t);
		virtual	void	callback_function	(r2_class_t, r2_code_t);
};




class r5_output_handler_symbol : public r5_output_handler	{
	public:
		virtual	void	callback_begin		(void);
		virtual	void	callback_end		(void);
		virtual	void	callback_code		(r2_code_t);
		virtual	void	callback_function	(r2_class_t, r2_code_t);


	public:
		virtual	void	execute		(void);
};




#endif

#endif