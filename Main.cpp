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
      const int16_t src1[5] = {0, 1, 2, 3, 4};
      const int16_t src2[5] = {1, 2, 3, 4, 5};
      auto lhs = simde_mm_setr_epi16(src1[0], src1[1], src1[2], src1[3], src1[4], 0, 0, 0);
      auto rhs = simde_mm_setr_epi16(src2[0], src2[1], src2[2], src2[3], src2[4], 0, 0, 0);
      auto res = simde_mm_cmpeq_epi16(lhs, rhs);
      auto mov = simde_mm_movemask_epi8(simde_mm_packs_epi16(res, simde_mm_setzero_si128()));
      if (mov != 224)
         return -1;
   }

   {
      // Failing case                                                   
      const char16_t src1[5] = {0, 1, 2, 3, 4};
      const char16_t src2[5] = {1, 2, 3, 4, 5};
      auto lhs = simde_mm_setr_epi16(
         reinterpret_cast<const int16_t&>(src1[0]),
         reinterpret_cast<const int16_t&>(src1[1]),
         reinterpret_cast<const int16_t&>(src1[2]),
         reinterpret_cast<const int16_t&>(src1[3]),
         reinterpret_cast<const int16_t&>(src1[4]),
         0, 0, 0
      );
      auto rhs = simde_mm_setr_epi16(
         reinterpret_cast<const int16_t&>(src2[0]),
         reinterpret_cast<const int16_t&>(src2[1]),
         reinterpret_cast<const int16_t&>(src2[2]),
         reinterpret_cast<const int16_t&>(src2[3]),
         reinterpret_cast<const int16_t&>(src2[4]),
         0, 0, 0
      );
      auto res = simde_mm_cmpeq_epi16(lhs, rhs);
      auto mov = simde_mm_movemask_epi8(simde_mm_packs_epi16(res, simde_mm_setzero_si128()));
      if (mov != 224)
         return -1;
   }

   return 0;
}