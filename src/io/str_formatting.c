#include "io_42.h"

static size_t	get_padding(size_t len, unsigned mw, int prec)
{
	if (prec > -1 && (size_t)prec < len)
		return (mw > (unsigned)prec ? mw - (unsigned)prec : 0);
	else
		return (mw > len ? mw - len : 0);
}

int				str_formatting(t_string *pb, t_format *fmt, size_t arglen)
{
	size_t	pad;
	char	fill;

	fill = (fmt->f_zero) ? '0' : ' ';
	if ((pad = get_padding(arglen, fmt->min_width, fmt->prec)) == 0)
		return (0);
	string_set(pb, pb->len, pad, fill);
	return ((int)pad);
}
