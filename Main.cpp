#include <simde/x86/sse4.2.h>
#include <simde/x86/sse4.1.h>
#include <simde/x86/ssse3.h>
#include <simde/x86/sse3.h>
#include <simde/x86/sse2.h>
#include <simde/x86/sse.h>
#include <simde/x86/svml.h>

int main() {
   {
      // Control case                                                   
      auto lhs = simde_mm_setr_epi16(0, 1, 2, 3, 4, 0, 0, 0);
      auto rhs = simde_mm_setr_epi16(1, 2, 3, 4, 5, 0, 0, 0);
      auto res = simde_mm_cmpeq_epi16(lhs, rhs);
      auto mov = simde_mm_movemask_epi8(simde_mm_packs_epi16(res, simde_mm_setzero_si128()));
      if (mov != 224)
         return -1;
   }

   {
      // Failing case                                                   
      auto lhs = simde_mm_setr_epi16(char16_t(0), char16_t(1), char16_t(2), char16_t(3), char16_t(4), 0, 0, 0);
      auto rhs = simde_mm_setr_epi16(char16_t(1), char16_t(2), char16_t(3), char16_t(4), char16_t(5), 0, 0, 0);
      auto res = simde_mm_cmpeq_epi16(lhs, rhs);
      auto mov = simde_mm_movemask_epi8(simde_mm_packs_epi16(res, simde_mm_setzero_si128()));
      if (mov != 224)
         return -1;
   }

   return 0;
}