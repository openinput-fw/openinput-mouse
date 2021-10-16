/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2021 Rafael Silva <perigoso@riseup.net>
 */

#include "util/data.h"
#include "util/types.h"

#include "platform/samx7x/cache.h"
#include "platform/samx7x/eefc.h"
#include "platform/samx7x/pmc.h"
#include "platform/samx7x/systick.h"
#include "platform/samx7x/wdt.h"

void main()
{
	icache_disable();
	dcache_disable();

	wdt_disable();

	pmc_init(12000000UL, 0UL);
	pmc_init_usb();
	pmc_update_clock_tree();

	systick_init();

	for (;;) {
		delay_ms(500);
		// TODO: blinky
		delay_ms(500);
	}
}
