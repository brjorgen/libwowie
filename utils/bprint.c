#include "bprint.h"

static int	_strlen(char *s){
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	putstr(char *s){
	write(1, s, _strlen(s));
}

static char	*uitoa_base(unsigned int i, int base){
	char *base_string = "0123456789ABCDEF";
	static char s[36] = {0};
	unsigned int pos = 0;
	unsigned int tmp = i;

	while (tmp > 0){
		*(s + pos) = base_string[tmp % base];
		tmp /= base;
		pos++;
	}
	*(s + pos) = 0;
	pos--;

	unsigned int current = 0;
	unsigned int temp = 0;

	// rev string
	while (current < pos){
		temp = s[current];
		s[current] = *(s + pos);
		*(s + pos) = temp;
		current++;
		pos--;
	}
	return (s);
}

static char	*itoa_base(int i, int base){
	char *base_string = "0123456789ABCDEF";
	static char s[36] = {0};
	int pos = 0;
	int tmp = i;

	while (tmp > 0){
		*(s + pos) = base_string[tmp % base];
		tmp /= base;
		pos++;
	}
	*(s + pos) = 0;
	pos--;

	int current = 0;
	int temp = 0;

	// rev string
	while (current < pos){
		temp = s[current];
		s[current] = *(s + pos);
		*(s + pos) = temp;
		current++;
		pos--;
	}
	return (s);
}

static void	_strncpy(char *d, char *s, int n){
	char *s_cpy = s, *d_cpy = d;
	while (*s_cpy && n--){
		*d_cpy = *s_cpy;
		d_cpy++;
		s_cpy++;
	}
}

static void	_memset(uint8_t *d, uint8_t v, int n){
	while (--n > -1){
		*(d + n) = v;
	}
}

int     bprint(const char * restrict format, ...){
	static char buff[255] = {[0 ... 254] = 0}; /* buffer output instead of printing */
	char *s = (char *)format;
	uint32_t i = 0;
	uint32_t tmp = 0;
	_Bool typical_update = 0;

	union  {
		int i;
		char c;
		char *s;
		void *p;
	} type_vars;

	_memset((uint8_t *)buff, 0u, 255);

	va_list ap;
	va_start(ap, format);

	while (*s){
		while (*s && *s != '%'){
			*(buff + i) = *s;
			s++;
			i++;
			typical_update = 0;
		}

		switch (*(s + 1)) {

		case ('%'):
			*(buff + i) = '%';
			i++;
			s += 2;
			typical_update = 0;
			break;

		case('c'):
			type_vars.c = va_arg(ap, int);
			*(buff + i) = type_vars.c;
			i++;
			s += 2;
			typical_update = 0;
			break;

		case ('d'):
		case ('i'):
			type_vars.i = va_arg(ap, int);
			type_vars.s = itoa_base(type_vars.i, 10);
			typical_update = 1;
			break;

		case('u'):
			type_vars.i = va_arg(ap, unsigned int);
			type_vars.s = uitoa_base(type_vars.i, 10);
			typical_update = 1;
			break;

		case('x'):
			type_vars.i = va_arg(ap, unsigned int);
			type_vars.s = uitoa_base(type_vars.i, 16);
			typical_update = 1;
			break;

		case('o'):
			type_vars.i = va_arg(ap, unsigned int);
			type_vars.s = itoa_base(type_vars.i, 8);
			typical_update = 1;
			break;

		case ('s'):
			type_vars.s = va_arg(ap, char *);
			typical_update = 1;
			break;

		/* case('p'): */
		/* 	type_vars.p = va_arg(ap, void *); */
		/* 	type_vars.s = itoa_base((uint32_t *)type_vars.p, 16); */
		/* 	i += _strlen(type_vars.s); */

		/* 	s += 2; */
		/* 	putstr(type_vars.s); */
		/* 	break; */

		case (0):
		default:
			break;
		}
		if (typical_update){
			tmp = i;
			i += _strlen(type_vars.s);
			_strncpy(buff + tmp, type_vars.s, _strlen(type_vars.s));
			s += 2;
		}
	}
	va_end(ap);
	putstr(buff);
	return (i);
}

/* 📝: todo: */
/* 📝: do boundary checks on buffer writes */
/* 📝: flush  buffer when full so we can write more */
/* 📝: add more options */
/* 📝: implement flag mechanism */
