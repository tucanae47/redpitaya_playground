#include <unistd.h>
#include "context.hpp"

class LedBlinker
{
  public:
    LedBlinker(Context& ctx)
    : ctl(ctx.mm.get<mem::control>())
    , sts(ctx.mm.get<mem::status>())
    {}

    void set_leds(uint32_t led_value) {
        ctl.write<reg::led>(led_value);
    }

    uint32_t get_leds() {
        return ctl.read<reg::led>();
    }

    void set_led(uint32_t index, bool status) {
        ctl.write_bit_reg(reg::led, index, status);
    }

    uint32_t get_forty_two() {
        return sts.read<reg::forty_two>();
    }

  private:
    Memory<mem::control>& ctl;
    Memory<mem::status>& sts;
};

int main() {

    Context ctx;
    ctx.init();
    LedBlinker play(ctx);
    printf("42 ? %d\n", play.get_forty_two());
    for (int i =0; i< 255; i++){
 	play.set_leds(i); 
	sleep(1);
    }
    printf("SUCESS \n");
    return 0;
}
