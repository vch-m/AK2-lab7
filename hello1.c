// SPDX-License-Identifier: GPL-3.0-only

#include "hello1.h"

MODULE_AUTHOR("Malashkin Viacheslav");
MODULE_DESCRIPTION("Parameter-counter of printing out the message");
MODULE_LICENSE("Dual BSD/GPL");

LIST_HEAD(list);

int print_hello(uint t)
{
	if (t == 0) {
		pr_warn("The parameter is equaled to zero\n");
	} else if (t > 5 && t <= 10) {
		pr_warn("The parameter is between 5 and 10\n");
	} else if (t > 0 && t <= 5) {
		int i = 0;

		for (; i < t; i++) {
			if (t == 5) {
				data = 0;
			} else {
				data = kmalloc(sizeof(*data), GFP_KERNEL);
			}

			ktime_t before = ktime_get();
			pr_alert("Hello, world!\n");
			data->time = ktime_sub(ktime_get(), before);
			list_add_tail(&(data->list), &list);
		}
	} else {
		BUG_ON(1);
	}

	return 0;
}
EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void)
{
	pr_info("hello1 init!\n");
	return 0;
}

static void __exit hello1_exit(void)
{

	list_for_each_safe(elem, safe, &list) {
		data = list_entry(elem, struct hello_data, list);
		pr_alert("print ktime: %lu\n", (unsigned long) data->time);
		list_del(elem);
		kfree(data);
	}
}

module_init(hello1_init);
module_exit(hello1_exit);
