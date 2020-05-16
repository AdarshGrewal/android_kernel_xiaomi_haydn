// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2019-2020, The Linux Foundation. All rights reserved.
 */

#include <linux/module.h>
#include <linux/percpu.h>
#include <linux/hrtimer.h>
#include <linux/sched.h>
#include <linux/math64.h>
#include "walt.h"
#include <trace/events/sched.h>
static DEFINE_PER_CPU(u64,WALT5c03c65a13);static DEFINE_PER_CPU(u64,
WALTde16cdc0f2);static DEFINE_PER_CPU(u64,WALT95bc2af379);static DEFINE_PER_CPU(
u64,nr);static DEFINE_PER_CPU(u64,nr_max);static DEFINE_PER_CPU(spinlock_t,
WALTe6ee2b56c7)=__SPIN_LOCK_UNLOCKED(WALTe6ee2b56c7);static s64 WALTd1b16ed698;
unsigned int sysctl_sched_busy_hyst_enable_cpus;unsigned int 
sysctl_sched_busy_hyst;unsigned int sysctl_sched_coloc_busy_hyst_enable_cpus=
(0x467+7094-0x1fad);unsigned int sysctl_sched_coloc_busy_hyst_cpu[NR_CPUS]={[
(0x1c0c+73-0x1c55)...NR_CPUS-(0x1359+2539-0x1d43)]=39000000};unsigned int 
sysctl_sched_coloc_busy_hyst_max_ms=(0x22ed+311-0x109c);unsigned int 
sysctl_sched_coloc_busy_hyst_cpu_busy_pct[NR_CPUS]={[(0xb0+3035-0xc8b)...NR_CPUS
-(0x201b+1139-0x248d)]=(0x156f+4079-0x2554)};static DEFINE_PER_CPU(atomic64_t,
WALT739b44b3f3)=ATOMIC64_INIT((0x2b4+2002-0xa86));static DEFINE_PER_CPU(u64,
WALT701fb8f8ec);static DEFINE_PER_CPU(u64,WALTe6a70b82b5);static DEFINE_PER_CPU(
u64,WALTd437d08ea3);
#define WALTcc368a061f		(0x268+4147-0x128c)
#define WALT74fd8dfb0d (sysctl_sched_coloc_busy_hyst_max_ms * NSEC_PER_MSEC)
void sched_get_nr_running_avg(struct sched_avg_stats*WALTf0f82ef4d0){int 
WALT8f9ab72eb9;u64 WALT3822d537f6=sched_clock();u64 WALT65b7325c24=
WALT3822d537f6-WALTd1b16ed698;u64 WALT42db3f0aea,WALT346aee5ac3;bool 
WALT6f04dcfcbc=false;if(!WALT65b7325c24)return;for_each_possible_cpu(
WALT8f9ab72eb9){unsigned long WALT05b7c9a580;u64 WALT1f1d98d140;
spin_lock_irqsave(&per_cpu(WALTe6ee2b56c7,WALT8f9ab72eb9),WALT05b7c9a580);
WALT3822d537f6=sched_clock();WALT1f1d98d140=WALT3822d537f6-per_cpu(
WALTde16cdc0f2,WALT8f9ab72eb9);BUG_ON((s64)WALT1f1d98d140<(0x116+6648-0x1b0e));
WALT42db3f0aea=per_cpu(WALT5c03c65a13,WALT8f9ab72eb9);WALT42db3f0aea+=per_cpu(nr
,WALT8f9ab72eb9)*WALT1f1d98d140;WALT42db3f0aea=div64_u64((WALT42db3f0aea*
(0x6c5+410-0x7fb)),WALT65b7325c24);WALT346aee5ac3=per_cpu(WALT95bc2af379,
WALT8f9ab72eb9);WALT346aee5ac3+=walt_big_tasks(WALT8f9ab72eb9)*WALT1f1d98d140;
WALT346aee5ac3=div64_u64((WALT346aee5ac3*(0x1f30+792-0x21e4)),WALT65b7325c24);
WALTf0f82ef4d0[WALT8f9ab72eb9].nr=(int)div64_u64((WALT42db3f0aea+WALTcc368a061f)
,(0x778+7767-0x256b));WALTf0f82ef4d0[WALT8f9ab72eb9].nr_misfit=(int)div64_u64((
WALT346aee5ac3+WALTcc368a061f),(0x2dd+4754-0x150b));WALTf0f82ef4d0[
WALT8f9ab72eb9].nr_max=per_cpu(nr_max,WALT8f9ab72eb9);WALTf0f82ef4d0[
WALT8f9ab72eb9].nr_scaled=WALT42db3f0aea;trace_sched_get_nr_running_avg(
WALT8f9ab72eb9,WALTf0f82ef4d0[WALT8f9ab72eb9].nr,WALTf0f82ef4d0[WALT8f9ab72eb9].
nr_misfit,WALTf0f82ef4d0[WALT8f9ab72eb9].nr_max,WALTf0f82ef4d0[WALT8f9ab72eb9].
nr_scaled);per_cpu(WALTde16cdc0f2,WALT8f9ab72eb9)=WALT3822d537f6;per_cpu(
WALT5c03c65a13,WALT8f9ab72eb9)=(0x1dbb+1077-0x21f0);per_cpu(WALT95bc2af379,
WALT8f9ab72eb9)=(0xe6a+5942-0x25a0);per_cpu(nr_max,WALT8f9ab72eb9)=per_cpu(nr,
WALT8f9ab72eb9);spin_unlock_irqrestore(&per_cpu(WALTe6ee2b56c7,WALT8f9ab72eb9),
WALT05b7c9a580);}for_each_possible_cpu(WALT8f9ab72eb9){if(per_cpu(WALTd437d08ea3
,WALT8f9ab72eb9)){WALT6f04dcfcbc=true;break;}}if(WALT6f04dcfcbc&&
get_rtgb_active_time()>=WALT74fd8dfb0d)sched_update_hyst_times();WALTd1b16ed698=
WALT3822d537f6;}EXPORT_SYMBOL(sched_get_nr_running_avg);void 
sched_update_hyst_times(void){bool WALTe5f9c419f8;int WALT8f9ab72eb9;unsigned 
long WALTc752305af9,WALT523e5f5a97;WALTe5f9c419f8=is_rtgb_active()&&(sched_boost
()!=CONSERVATIVE_BOOST)&&(get_rtgb_active_time()<WALT74fd8dfb0d);
for_each_possible_cpu(WALT8f9ab72eb9){WALTc752305af9=arch_scale_cpu_capacity(
WALT8f9ab72eb9);WALT523e5f5a97=sysctl_sched_coloc_busy_hyst_cpu_busy_pct[
WALT8f9ab72eb9];per_cpu(WALT701fb8f8ec,WALT8f9ab72eb9)=(BIT(WALT8f9ab72eb9)&
sysctl_sched_busy_hyst_enable_cpus)?sysctl_sched_busy_hyst:(0x1ae3+1350-0x2029);
per_cpu(WALTd437d08ea3,WALT8f9ab72eb9)=((BIT(WALT8f9ab72eb9)&
sysctl_sched_coloc_busy_hyst_enable_cpus)&&WALTe5f9c419f8)?
sysctl_sched_coloc_busy_hyst_cpu[WALT8f9ab72eb9]:(0xfcf+88-0x1027);per_cpu(
WALTe6a70b82b5,WALT8f9ab72eb9)=mult_frac(WALTc752305af9,WALT523e5f5a97,
(0x21a5+563-0x2374));}}
#define WALT8dd50955b9		(0x2cb+6028-0x1a54)
#define WALTed8d29ed55	(0x62c+6303-0x1ec1)
static inline void WALTecd7b5dadc(int WALT8f9ab72eb9,bool WALTea3d214cf5,
unsigned long WALTa70cd3cf53,u64 WALT3822d537f6){bool WALT164d00420c=false;bool 
WALTb616236140=false,WALTb25f184b7b=false;u64 WALT0150aac757;if(!per_cpu(
WALT701fb8f8ec,WALT8f9ab72eb9)&&!per_cpu(WALTd437d08ea3,WALT8f9ab72eb9))return;
if(WALTa70cd3cf53>=WALT8dd50955b9&&per_cpu(nr,WALT8f9ab72eb9)<WALT8dd50955b9)
WALT164d00420c=true;if(WALTea3d214cf5&&(cpu_util(WALT8f9ab72eb9)*WALTed8d29ed55)
>capacity_orig_of(WALT8f9ab72eb9))WALTb616236140=true;if(WALTea3d214cf5&&
cpu_util(WALT8f9ab72eb9)>per_cpu(WALTe6a70b82b5,WALT8f9ab72eb9))WALTb25f184b7b=
true;WALT0150aac757=max((WALT164d00420c||WALTb616236140)?per_cpu(WALT701fb8f8ec,
WALT8f9ab72eb9):(0x1494+348-0x15f0),(WALT164d00420c||WALTb25f184b7b)?per_cpu(
WALTd437d08ea3,WALT8f9ab72eb9):(0x1f13+1706-0x25bd));if(WALT0150aac757)
atomic64_set(&per_cpu(WALT739b44b3f3,WALT8f9ab72eb9),WALT3822d537f6+
WALT0150aac757);}int sched_busy_hyst_handler(struct ctl_table*WALT047dc75d0e,int
 WALT123284dc15,void __user*WALTfc9cd6af11,size_t*WALTc6af6558dd,loff_t*
WALT9057b9d303){int WALT083920bcc8;if(WALT047dc75d0e->maxlen>(sizeof(unsigned 
int)*num_possible_cpus()))WALT047dc75d0e->maxlen=sizeof(unsigned int)*
num_possible_cpus();WALT083920bcc8=proc_dointvec_minmax(WALT047dc75d0e,
WALT123284dc15,WALTfc9cd6af11,WALTc6af6558dd,WALT9057b9d303);if(!WALT083920bcc8
&&WALT123284dc15)sched_update_hyst_times();return WALT083920bcc8;}void 
sched_update_nr_prod(int WALT8f9ab72eb9,long WALT17abc14e87,bool WALTef3ecb031d)
{u64 WALT1f1d98d140;u64 WALT3822d537f6;unsigned long WALT05b7c9a580,
WALT8a91c84c00;spin_lock_irqsave(&per_cpu(WALTe6ee2b56c7,WALT8f9ab72eb9),
WALT05b7c9a580);WALT8a91c84c00=per_cpu(nr,WALT8f9ab72eb9);WALT3822d537f6=
sched_clock();WALT1f1d98d140=WALT3822d537f6-per_cpu(WALTde16cdc0f2,
WALT8f9ab72eb9);BUG_ON((s64)WALT1f1d98d140<(0x1480+2366-0x1dbe));per_cpu(
WALTde16cdc0f2,WALT8f9ab72eb9)=WALT3822d537f6;per_cpu(nr,WALT8f9ab72eb9)=
WALT8a91c84c00+(WALTef3ecb031d?WALT17abc14e87:-WALT17abc14e87);BUG_ON((s64)
per_cpu(nr,WALT8f9ab72eb9)<(0xc45+2421-0x15ba));if(per_cpu(nr,WALT8f9ab72eb9)>
per_cpu(nr_max,WALT8f9ab72eb9))per_cpu(nr_max,WALT8f9ab72eb9)=per_cpu(nr,
WALT8f9ab72eb9);WALTecd7b5dadc(WALT8f9ab72eb9,!WALTef3ecb031d,WALT8a91c84c00,
WALT3822d537f6);per_cpu(WALT5c03c65a13,WALT8f9ab72eb9)+=WALT8a91c84c00*
WALT1f1d98d140;per_cpu(WALT95bc2af379,WALT8f9ab72eb9)+=walt_big_tasks(
WALT8f9ab72eb9)*WALT1f1d98d140;spin_unlock_irqrestore(&per_cpu(WALTe6ee2b56c7,
WALT8f9ab72eb9),WALT05b7c9a580);}EXPORT_SYMBOL(sched_update_nr_prod);unsigned 
int sched_get_cpu_util(int WALT8f9ab72eb9){struct rq*rq=cpu_rq(WALT8f9ab72eb9);
u64 WALTb0b0149580;unsigned long WALTfbbdeffe9c,WALT05b7c9a580;unsigned int 
WALT517f9bdd84;raw_spin_lock_irqsave(&rq->lock,WALT05b7c9a580);WALTfbbdeffe9c=
capacity_orig_of(WALT8f9ab72eb9);WALTb0b0149580=rq->prev_runnable_sum+rq->
grp_time.prev_runnable_sum;WALTb0b0149580=div64_u64(WALTb0b0149580,
sched_ravg_window>>SCHED_CAPACITY_SHIFT);raw_spin_unlock_irqrestore(&rq->lock,
WALT05b7c9a580);WALTb0b0149580=(WALTb0b0149580>=WALTfbbdeffe9c)?WALTfbbdeffe9c:
WALTb0b0149580;WALT517f9bdd84=div64_ul((WALTb0b0149580*(0xb63+4320-0x1bdf)),
WALTfbbdeffe9c);return WALT517f9bdd84;}u64 sched_lpm_disallowed_time(int 
WALT8f9ab72eb9){u64 WALT2c53bb3f34=sched_clock();u64 WALT09c73f1899=
atomic64_read(&per_cpu(WALT739b44b3f3,WALT8f9ab72eb9));if(WALT2c53bb3f34<
WALT09c73f1899)return WALT09c73f1899-WALT2c53bb3f34;return(0xb66+6722-0x25a8);}
