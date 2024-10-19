#include <simde/x86/sse4.2.h>
#include <simde/x86/sse4.1.h>
#include <simde/x86/ssse3.h>
#include <simde/x86/sse3.h>
#include <simde/x86/sse2.h>
#include <simde/x86/sse.h>
#include <simde/x86/svml.h>

int main() {
   auto lhs = simde_mm_setr_epi16(0, 1, 2, 3, 4, 0, 0, 0);
   auto rhs = simde_mm_setr_epi16(1, 2, 3, 4, 5, 0, 0, 0);
   auto res = simde_mm_cmpeq_epi16(lhs, rhs);
   auto mov = simde_mm_movemask_epi8(simde_mm_packs_epi16(res, simde_mm_setzero_si128()));

   return mov == 224 ? 0 : -1;
}