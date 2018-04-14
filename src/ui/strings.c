/*
 * strings.c: Implementation of default UI strings
 *
 * Copyright (C) 2017 Frank Morgner <frankmorgner@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "libopensc/internal.h"
#include "ui/strings.h"
#include <stdlib.h>
#include <string.h>

const char *ui_get_config_str(struct sc_context *ctx,
		struct sc_atr *atr, const char *flag_name, const char *ret_default)
{
	const char *ret = ret_default;

	scconf_block *atrblock = _sc_match_atr_block(ctx, NULL, atr);

	if (atrblock)
		ret = scconf_get_str(atrblock, flag_name, ret_default);

	return ret;
}

void ui_localize_str(const char *preferred)
{
	if (preferred) {
		if (0 == strncmp(preferred, "de", 2)) {
			setenv("LANG", "de_DE", 1);
		} else if (0 == strncmp(preferred, "en", 2)) {
			setenv("LANG", "en_US", 1);
		}
	}
#ifdef ENABLE_NLS
	setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE, LOCALEDIR);
	textdomain(PACKAGE);
#endif
}
