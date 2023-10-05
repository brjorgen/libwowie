#include "./wowie_stacks.h"

const	char *__g_error_stk_messages[__E_STK_MAX_ERR] = {
	[E_STACK_FULL] = "Stack's full.",
	[E_STACK_EMPTY] = "Stack's empty.",
	[E_STACK_OK] = "Stack's all good.",
	[E_STACK_ALLOC_FAILED] = "An Allocation has failed.",
	[E_STACK_ABNORMAL] = "Stack is either empty, full or both."
};
