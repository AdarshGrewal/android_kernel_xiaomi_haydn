// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2019-2020, The Linux Foundation. All rights reserved.
 */

#define pr_fmt(zc4af4bede1) "\x63\x70\x75\x2d\x62\x6f\x6f\x73\x74\x3a\x20" \
zc4af4bede1
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/cpufreq.h>
#include <linux/cpu.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/input.h>
#include <linux/time.h>
#include <linux/sysfs.h>
#include <linux/pm_qos.h>
#include "walt.h"
#define cpu_boost_attr_rw(zb25dfb9431)		\
static struct kobj_attribute zb25dfb9431##_attr =	\
__ATTR(zb25dfb9431, (0x11eb+3984-0x1fd7), show_##zb25dfb9431, store_##\
zb25dfb9431)
#define z4fd2c65c70(z424312941f)			\
static ssize_t show_##z424312941f			\
(struct kobject *kobj, struct kobj_attribute *attr, char *z33c5f8b4bc)	\
{								\
	return scnprintf(z33c5f8b4bc, PAGE_SIZE, "\x25\x75" "\n", z424312941f);	\
}
#define z110aa7e285(z424312941f)					\
static ssize_t store_##z424312941f				\
(struct kobject *kobj, struct kobj_attribute *attr,		\
const char *z33c5f8b4bc, size_t z33ea1b60d7)					\
{								\
								\
	sscanf(z33c5f8b4bc, "\x25\x75", &z424312941f);				\
	return z33ea1b60d7;						\
}
struct zce6d56b8bb{int cpu;unsigned int input_boost_min;unsigned int 
input_boost_freq;};static DEFINE_PER_CPU(struct zce6d56b8bb,zdd15390acf);static 
struct workqueue_struct*z9762523439;static struct work_struct z22a243569d;static
 bool z9f1a9f39a2;static unsigned int input_boost_ms=(0xc37+5571-0x21d2);
z4fd2c65c70(input_boost_ms);z110aa7e285(input_boost_ms);cpu_boost_attr_rw(
input_boost_ms);static unsigned int sched_boost_on_input;z4fd2c65c70(
sched_boost_on_input);z110aa7e285(sched_boost_on_input);cpu_boost_attr_rw(
sched_boost_on_input);static bool z83486149e3;static struct delayed_work 
ze22e8298ec;static u64 z4ecacf5b3e;
#define MIN_INPUT_INTERVAL ((0x1aa3+3165-0x266a) * USEC_PER_MSEC)
static struct dev_pm_qos_request zb79580c5cb;static ssize_t 
store_input_boost_freq(struct kobject*kobj,struct kobj_attribute*attr,const char
*z33c5f8b4bc,size_t z33ea1b60d7){int z5d971be8b8,z363309dafd=(0x5e1+3215-0x1270)
;unsigned int zc94d3d8015,cpu;const char*z55398c375d=z33c5f8b4bc;bool 
z097cdda7e5=false;while((z55398c375d=strpbrk(z55398c375d+(0x5f8+2541-0xfe4),
"\x20\x3a")))z363309dafd++;if(!z363309dafd){if(sscanf(z33c5f8b4bc,
"\x25\x75" "\n",&zc94d3d8015)!=(0xe45+2684-0x18c0))return-EINVAL;
for_each_possible_cpu(z5d971be8b8)per_cpu(zdd15390acf,z5d971be8b8).
input_boost_freq=zc94d3d8015;goto z94baffc55b;}if(!(z363309dafd%
(0xf30+4287-0x1fed)))return-EINVAL;z55398c375d=z33c5f8b4bc;for(z5d971be8b8=
(0x40c+634-0x686);z5d971be8b8<z363309dafd;z5d971be8b8+=(0xd2a+4510-0x1ec6)){if(
sscanf(z55398c375d,"\x25\x75\x3a\x25\x75",&cpu,&zc94d3d8015)!=
(0x1211+698-0x14c9))return-EINVAL;if(cpu>=num_possible_cpus())return-EINVAL;
per_cpu(zdd15390acf,cpu).input_boost_freq=zc94d3d8015;z55398c375d=strnchr(
z55398c375d,PAGE_SIZE-(z55398c375d-z33c5f8b4bc),((char)(0xe98+1664-0x14f8)));
z55398c375d++;}z94baffc55b:for_each_possible_cpu(z5d971be8b8){if(per_cpu(
zdd15390acf,z5d971be8b8).input_boost_freq){z097cdda7e5=true;break;}}z9f1a9f39a2=
z097cdda7e5;return z33ea1b60d7;}static ssize_t show_input_boost_freq(struct 
kobject*kobj,struct kobj_attribute*attr,char*z33c5f8b4bc){int zb5bf6cca69=
(0xba3+6728-0x25eb),cpu;struct zce6d56b8bb*ze4d1b656b7;for_each_possible_cpu(cpu
){ze4d1b656b7=&per_cpu(zdd15390acf,cpu);zb5bf6cca69+=snprintf(z33c5f8b4bc+
zb5bf6cca69,PAGE_SIZE-zb5bf6cca69,"\x25\x64\x3a\x25\x75\x20",cpu,ze4d1b656b7->
input_boost_freq);}zb5bf6cca69+=snprintf(z33c5f8b4bc+zb5bf6cca69,PAGE_SIZE-
zb5bf6cca69,"\n");return zb5bf6cca69;}cpu_boost_attr_rw(input_boost_freq);static
 void z31eba71b41(void*zf8791a57cc){struct cpufreq_policy*z17deffe12c=
zf8791a57cc;unsigned int cpu=z17deffe12c->cpu;struct zce6d56b8bb*ze4d1b656b7=&
per_cpu(zdd15390acf,cpu);unsigned int zd51b8e5a9b=ze4d1b656b7->input_boost_min;
int z083920bcc8;if(!zd51b8e5a9b)return;pr_debug(
"\x43\x50\x55\x25\x75\x20\x70\x6f\x6c\x69\x63\x79\x20\x6d\x69\x6e\x20\x62\x65\x66\x6f\x72\x65\x20\x62\x6f\x6f\x73\x74\x3a\x20\x25\x75\x20\x6b\x48\x7a" "\n"
,cpu,z17deffe12c->min);pr_debug(
"\x43\x50\x55\x25\x75\x20\x62\x6f\x6f\x73\x74\x20\x6d\x69\x6e\x3a\x20\x25\x75\x20\x6b\x48\x7a" "\n"
,cpu,zd51b8e5a9b);z083920bcc8=dev_pm_qos_update_request(&zb79580c5cb,zd51b8e5a9b
);if(z083920bcc8<(0x1941+1097-0x1d8a))pr_err(
"\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x75\x70\x64\x61\x74\x65\x20\x66\x72\x65\x71\x20\x63\x6f\x6e\x73\x74\x72\x61\x69\x6e\x74\x20\x69\x6e\x20\x62\x6f\x6f\x73\x74\x5f\x61\x64\x6a\x75\x73\x74\x3a\x20\x25\x64" "\n"
,zd51b8e5a9b);pr_debug(
"\x43\x50\x55\x25\x75\x20\x70\x6f\x6c\x69\x63\x79\x20\x6d\x69\x6e\x20\x61\x66\x74\x65\x72\x20\x62\x6f\x6f\x73\x74\x3a\x20\x25\x75\x20\x6b\x48\x7a" "\n"
,cpu,z17deffe12c->min);return;}static void z5368534a89(void){unsigned int 
z5d971be8b8;struct cpufreq_policy*z17deffe12c;get_online_cpus();
for_each_online_cpu(z5d971be8b8){if(z5d971be8b8==(0x644+2456-0xfdc)){z17deffe12c
=cpufreq_cpu_get(z5d971be8b8);if(!z17deffe12c){pr_err(
"\x25\x73\x3a\x20\x63\x70\x75\x66\x72\x65\x71\x20\x70\x6f\x6c\x69\x63\x79\x20\x6e\x6f\x74\x20\x66\x6f\x75\x6e\x64\x20\x66\x6f\x72\x20\x63\x70\x75\x25\x64" "\n"
,__func__,z5d971be8b8);return;}z31eba71b41(&z17deffe12c);}pr_debug(
"\x55\x70\x64\x61\x74\x69\x6e\x67\x20\x70\x6f\x6c\x69\x63\x79\x20\x66\x6f\x72\x20\x43\x50\x55\x25\x64" "\n"
,z5d971be8b8);cpufreq_update_policy(z5d971be8b8);}put_online_cpus();}static void
 z95de59aedd(struct work_struct*z9932a7275f){unsigned int z5d971be8b8,
z083920bcc8;struct zce6d56b8bb*z460c0e8c37;pr_debug(
"\x52\x65\x73\x65\x74\x74\x69\x6e\x67\x20\x69\x6e\x70\x75\x74\x20\x62\x6f\x6f\x73\x74\x20\x6d\x69\x6e\x20\x66\x6f\x72\x20\x61\x6c\x6c\x20\x43\x50\x55\x73" "\n"
);for_each_possible_cpu(z5d971be8b8){z460c0e8c37=&per_cpu(zdd15390acf,
z5d971be8b8);z460c0e8c37->input_boost_min=(0x1eb7+1374-0x2415);}z5368534a89();if
(z83486149e3){z083920bcc8=sched_set_boost((0x365+7789-0x21d2));if(z083920bcc8)
pr_err(
"\x63\x70\x75\x2d\x62\x6f\x6f\x73\x74\x3a\x20\x73\x63\x68\x65\x64\x20\x62\x6f\x6f\x73\x74\x20\x64\x69\x73\x61\x62\x6c\x65\x20\x66\x61\x69\x6c\x65\x64" "\n"
);z83486149e3=false;}}static void z1ee1f01166(struct work_struct*z9932a7275f){
unsigned int z5d971be8b8,z083920bcc8;struct zce6d56b8bb*z460c0e8c37;
cancel_delayed_work_sync(&ze22e8298ec);if(z83486149e3){sched_set_boost(
(0xbcb+6550-0x2561));z83486149e3=false;}pr_debug(
"\x53\x65\x74\x74\x69\x6e\x67\x20\x69\x6e\x70\x75\x74\x20\x62\x6f\x6f\x73\x74\x20\x6d\x69\x6e\x20\x66\x6f\x72\x20\x61\x6c\x6c\x20\x43\x50\x55\x73" "\n"
);for_each_possible_cpu(z5d971be8b8){z460c0e8c37=&per_cpu(zdd15390acf,
z5d971be8b8);z460c0e8c37->input_boost_min=z460c0e8c37->input_boost_freq;}
z5368534a89();if(sched_boost_on_input>(0x33+9626-0x25cd)){z083920bcc8=
sched_set_boost(sched_boost_on_input);if(z083920bcc8)pr_err(
"\x63\x70\x75\x2d\x62\x6f\x6f\x73\x74\x3a\x20\x73\x63\x68\x65\x64\x20\x62\x6f\x6f\x73\x74\x20\x65\x6e\x61\x62\x6c\x65\x20\x66\x61\x69\x6c\x65\x64" "\n"
);else z83486149e3=true;}queue_delayed_work(z9762523439,&ze22e8298ec,
msecs_to_jiffies(input_boost_ms));}static void z0e336f2913(struct input_handle*
zb773b2097d,unsigned int z3e92d20441,unsigned int z5a776a7d24,int z95e2f0a380){
u64 z2c53bb3f34;if(!z9f1a9f39a2)return;z2c53bb3f34=ktime_to_us(ktime_get());if(
z2c53bb3f34-z4ecacf5b3e<MIN_INPUT_INTERVAL)return;if(work_pending(&z22a243569d))
return;queue_work(z9762523439,&z22a243569d);z4ecacf5b3e=ktime_to_us(ktime_get())
;}static int z86ec8ceef6(struct input_handler*handler,struct input_dev*dev,const
 struct input_device_id*zb13beca266){struct input_handle*zb773b2097d;int error;
zb773b2097d=kzalloc(sizeof(struct input_handle),GFP_KERNEL);if(!zb773b2097d)
return-ENOMEM;zb773b2097d->dev=dev;zb773b2097d->handler=handler;zb773b2097d->
name="\x63\x70\x75\x66\x72\x65\x71";error=input_register_handle(zb773b2097d);if(
error)goto z5b81047b49;error=input_open_device(zb773b2097d);if(error)goto 
zeafa714acc;return(0xaef+2601-0x1518);zeafa714acc:input_unregister_handle(
zb773b2097d);z5b81047b49:kfree(zb773b2097d);return error;}static void 
z8758b5addd(struct input_handle*zb773b2097d){input_close_device(zb773b2097d);
input_unregister_handle(zb773b2097d);kfree(zb773b2097d);}static const struct 
input_device_id z6a35b945c0[]={{.flags=INPUT_DEVICE_ID_MATCH_EVBIT|
INPUT_DEVICE_ID_MATCH_ABSBIT,.evbit={BIT_MASK(EV_ABS)},.absbit={[BIT_WORD(
ABS_MT_POSITION_X)]=BIT_MASK(ABS_MT_POSITION_X)|BIT_MASK(ABS_MT_POSITION_Y)},},{
.flags=INPUT_DEVICE_ID_MATCH_KEYBIT|INPUT_DEVICE_ID_MATCH_ABSBIT,.keybit={[
BIT_WORD(BTN_TOUCH)]=BIT_MASK(BTN_TOUCH)},.absbit={[BIT_WORD(ABS_X)]=BIT_MASK(
ABS_X)|BIT_MASK(ABS_Y)},},{.flags=INPUT_DEVICE_ID_MATCH_EVBIT,.evbit={BIT_MASK(
EV_KEY)},},{},};static struct input_handler z56003a1ee4={.event=z0e336f2913,.
connect=z86ec8ceef6,.disconnect=z8758b5addd,.name=
"\x63\x70\x75\x2d\x62\x6f\x6f\x73\x74",.id_table=z6a35b945c0,};struct kobject*
cpu_boost_kobj;static int zdeb0b46b63(void){int cpu,z083920bcc8;struct 
zce6d56b8bb*ze4d1b656b7;struct device*zae2bf80696;struct cpufreq_policy*
z17deffe12c;z9762523439=alloc_workqueue(
"\x63\x70\x75\x62\x6f\x6f\x73\x74\x5f\x77\x71",WQ_HIGHPRI,(0x1226+5257-0x26af));
if(!z9762523439)return-EFAULT;INIT_WORK(&z22a243569d,z1ee1f01166);
INIT_DELAYED_WORK(&ze22e8298ec,z95de59aedd);for_each_possible_cpu(cpu){
ze4d1b656b7=&per_cpu(zdd15390acf,cpu);ze4d1b656b7->cpu=cpu;if(cpu==
(0x1edc+555-0x2107)){z17deffe12c=cpufreq_cpu_get(cpu);if(!z17deffe12c){pr_err(
"\x25\x73\x3a\x20\x63\x70\x75\x66\x72\x65\x71\x20\x70\x6f\x6c\x69\x63\x79\x20\x6e\x6f\x74\x20\x66\x6f\x75\x6e\x64\x20\x66\x6f\x72\x20\x63\x70\x75\x25\x64" "\n"
,__func__,cpu);return-(0x3c4+6929-0x1ed4);}zae2bf80696=get_cpu_device(cpu);if(
unlikely(!zae2bf80696)){pr_err(
"\x25\x73\x3a\x20\x43\x50\x55\x20\x64\x65\x76\x69\x63\x65\x20\x6e\x6f\x74\x20\x66\x6f\x75\x6e\x64\x20\x66\x6f\x72\x20\x63\x70\x75\x25\x64" "\n"
,__func__,cpu);return-(0x93b+3295-0x1619);}z083920bcc8=dev_pm_qos_add_request(
zae2bf80696,&zb79580c5cb,DEV_PM_QOS_MIN_FREQUENCY,z17deffe12c->min);if(
z083920bcc8<(0xb8+5213-0x1515)){pr_err(
"\x25\x73\x3a\x20\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x61\x64\x64\x20\x66\x72\x65\x71\x20\x63\x6f\x6e\x73\x74\x72\x61\x69\x6e\x74\x20\x28\x25\x64\x29" "\n"
,__func__,z083920bcc8);goto z77e7361053;}}}cpu_boost_kobj=kobject_create_and_add
("\x63\x70\x75\x5f\x62\x6f\x6f\x73\x74",&cpu_subsys.dev_root->kobj);if(!
cpu_boost_kobj)pr_err(
"\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x69\x6e\x69\x74\x69\x61\x6c\x69\x7a\x65\x20\x73\x79\x73\x66\x73\x20\x6e\x6f\x64\x65\x20\x66\x6f\x72\x20\x63\x70\x75\x5f\x62\x6f\x6f\x73\x74\x2e" "\n"
);z083920bcc8=sysfs_create_file(cpu_boost_kobj,&input_boost_ms_attr.attr);if(
z083920bcc8)pr_err(
"\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x63\x72\x65\x61\x74\x65\x20\x69\x6e\x70\x75\x74\x5f\x62\x6f\x6f\x73\x74\x5f\x6d\x73\x20\x6e\x6f\x64\x65\x3a\x20\x25\x64" "\n"
,z083920bcc8);z083920bcc8=sysfs_create_file(cpu_boost_kobj,&
input_boost_freq_attr.attr);if(z083920bcc8)pr_err(
"\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x63\x72\x65\x61\x74\x65\x20\x69\x6e\x70\x75\x74\x5f\x62\x6f\x6f\x73\x74\x5f\x66\x72\x65\x71\x20\x6e\x6f\x64\x65\x3a\x20\x25\x64" "\n"
,z083920bcc8);z083920bcc8=sysfs_create_file(cpu_boost_kobj,&
sched_boost_on_input_attr.attr);if(z083920bcc8)pr_err(
"\x46\x61\x69\x6c\x65\x64\x20\x74\x6f\x20\x63\x72\x65\x61\x74\x65\x20\x73\x63\x68\x65\x64\x5f\x62\x6f\x6f\x73\x74\x5f\x6f\x6e\x5f\x69\x6e\x70\x75\x74\x20\x6e\x6f\x64\x65\x3a\x20\x25\x64" "\n"
,z083920bcc8);z083920bcc8=input_register_handler(&z56003a1ee4);return
(0x135a+4598-0x2550);z77e7361053:dev_pm_qos_remove_request(&zb79580c5cb);return 
z083920bcc8;}late_initcall(zdeb0b46b63);
