#ifndef _ERROR_H_
#define _ERROR_H_

/*
** Implement these as part of the interface of your module:

** extern const char *__g_error_[modname]_messages[__E_[modname]_MAX_ERR];
** # define MODULE_ERR_ARRAY __g_error_[modname]_messages
** # define [modname]ERR(errcode) error(__FUNCTION__, errcode, __g_error_[modname]_messages)

*/

void	error(const char *function,			// __FUNCTION__
	      const char *file,				// __FILE__
	      const int file_line,			// __LINE__
	      int error_code,				// Enumerated error code defined in module header
	      const char *__error_message_array[]);	// array of error strings

#endif /* _ERROR_H_ */
