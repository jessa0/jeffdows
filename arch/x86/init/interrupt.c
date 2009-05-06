#include <mem/segment.h>
#include <init/asm.h>
#include "interrupt.h"

descriptor_t idt[IDT_SIZE];

void init_interrupts() {
  nonpresent_descriptor_t nonpresent_gate = {
    .present = 0
  };
  for (int i = 0; i < IDT_SIZE; i++)
    idt[i].nonpresent = nonpresent_gate;

  pseudo_segment_descriptor_t idtd = {
    (sizeof(idt) - 1),
    (unsigned) &idt
  };
  set_idt(&idtd);
}
