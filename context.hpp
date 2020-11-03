/// (c) Koheron

#ifndef __CONTEXT_HPP__
#define __CONTEXT_HPP__

#include "memory_manager.hpp"
#include "spi_dev.hpp"
#include "i2c_dev.hpp"
#include "zynq_fclk.hpp"
#include "fpga_manager.hpp"


class Context
{
  public:
    Context()
    : mm()
    , spi()
    , i2c()
    , fclk()
    , fpga()
    {
        if (fpga.load_bitstream(instrument_name) < 0) {
            exit(EXIT_FAILURE);
        }

        // We set all the Zynq clocks before starting the drivers
        zynq_clocks::set_clocks(fclk);
    }

    int init() {
        if (mm.open() < 0  ||
            spi.init() < 0 ||
            i2c.init() < 0)
            return -1;

        return 0;
    }

    MemoryManager mm;
    SpiManager spi;
    I2cManager i2c;
    ZynqFclk fclk;
    FpgaManager fpga;
};

#endif // __CONTEXT_HPP__
