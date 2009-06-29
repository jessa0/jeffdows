#ifndef _INIT_MEM_H
#define _INIT_MEM_H

#include <types.h>

typedef struct phys_mmap {
  phys_addr_t base_addr;
  size_t limit;
} phys_mmap_t;

void init_mem(phys_mmap_t *phys_mmap);

#endif
