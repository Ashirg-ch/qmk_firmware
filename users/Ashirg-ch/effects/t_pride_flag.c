/* Copyright 2023 Ashirg-ch <https://github.com/Ashirg-ch>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

RGB_MATRIX_EFFECT(T_PRIDE_FLAG)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

/** A static light effect that displays the transgender pride flag.
 * 
 * This effect assumes that the keyboard has at least five rows.
 * Any further rows will be ignored (turned off), only the upper five will be activated.
 * 
 * TODO: Test this implementation
 * 
 */
static bool T_PRIDE_FLAG(effect_params_t* params) {
	RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (index >= led_min && index < led_max && index != NO_LED) {
				switch (row) {
					case 0:
					case 4:
						rgb_matrix_set_color(index, 0x5B, 0xCE, 0xFA);
						break;
					case 1:
					case 3:
						rgb_matrix_set_color(index, 0xF5, 0xA9, 0xB8);
						break;
					case 2:
						rgb_matrix_set_color(index, RGB_WHITE);
                        break;
					default:
						rgb_matrix_set_color(index, RGB_BLACK);
						break;
				}
            }
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
