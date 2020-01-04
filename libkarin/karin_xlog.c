#include <cutils/log.h>

struct xlog_record {
	const char *tag_str;
	const char *fmt_str;
	int prio;
};

static void init(void) __attribute__ ((constructor));

void init(void)
{
}

int __xlog_buf_printf(int bufid, const struct xlog_record *rec, ...)
{
  va_list args;
  va_start(args, rec);
  va_end(args);

  return 0;
}
