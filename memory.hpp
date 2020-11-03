
#include <array>
#include <tuple>
#include <cstdint>

#include "zynq_fclk.hpp"

extern "C" {
  #include <sys/mman.h> // PROT_READ, PROT_WRITE
}

constexpr auto instrument_name = "led-blinker";

namespace mem {
constexpr size_t control = 0;
constexpr uintptr_t control_addr = 0x60000000;
constexpr uint32_t control_range = 4*1024;
constexpr uint32_t control_nblocks = 1;
constexpr size_t status = 1;
constexpr uintptr_t status_addr = 0x50000000;
constexpr uint32_t status_range = 4*1024;
constexpr uint32_t status_nblocks = 1;


constexpr size_t count = 2;

constexpr std::array<std::tuple<uintptr_t, uint32_t, uint32_t, uint32_t>, count> memory_array = {{
    std::make_tuple(control_addr, control_range, PROT_READ|PROT_WRITE, control_nblocks),
        std::make_tuple(status_addr, status_range, PROT_READ|PROT_WRITE, status_nblocks)
        }};

} // namespace mem

namespace reg {
// -- Control offsets
constexpr uint32_t led = 0;
static_assert(led < mem::control_range, "Invalid control register offset led");

// -- PS Control offsets

// -- Status offsets
constexpr uint32_t forty_two = 8;
static_assert(forty_two < mem::status_range, "Invalid status register offset forty_two");

// -- PS Status offsets


constexpr uint32_t dna = 0;
} // namespace reg

namespace prm {
constexpr uint32_t fclk0 = 50000000;


} // namespace prm

namespace zynq_clocks {

inline void set_clocks(ZynqFclk& fclk) {

fclk.set("fclk0", 50000000);


}
}
