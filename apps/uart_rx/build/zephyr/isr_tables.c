
/* AUTO-GENERATED by gen_isr_tables.py, do not edit! */

#include <zephyr/toolchain.h>
#include <zephyr/linker/sections.h>
#include <zephyr/sw_isr_table.h>
#include <zephyr/arch/cpu.h>

typedef void (* ISR)(const void *);
uintptr_t __irq_vector_table _irq_vector_table[60] = {
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
	((uintptr_t)&_isr_wrapper),
};
struct _isr_table_entry __sw_isr_table _sw_isr_table[60] = {
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x800660f, (ISR)0x80029e5},
	{(const void *)0x800660d, (ISR)0x80029e5},
	{(const void *)0x800660b, (ISR)0x80029e5},
	{(const void *)0x8006609, (ISR)0x80029e5},
	{(const void *)0x8006607, (ISR)0x80029e5},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x8006605, (ISR)0x80029e5},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x8005c28, (ISR)0x80056bd},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x8006603, (ISR)0x80029e5},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
	{(const void *)0x0, (ISR)((uintptr_t)&z_irq_spurious)},
};
