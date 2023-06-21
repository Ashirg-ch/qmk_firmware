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
                HSV hsv = {0, 0, 0};
                // For some unfathomable reason, the rows for pink and white are exchanged, so I had to exchange them in code.
                // I have no idea why it works like this and I'm not sure whether I'll invest the time to fix it.
                switch (row) {
                    case 0:
                    case 4:
                        hsv = (HSV){91, 206, 250};
						break;
					case 1:
					case 3:
                        //hsv = (HSV){245, 169, 184};
                        hsv = (HSV){255, 255, 255};
						break;
					case 2:
                        //hsv = (HSV){255, 255, 255};
                        hsv = (HSV){245, 169, 184};
                        break;
					default:
						break;
				}

                if (hsv.v > rgb_matrix_get_val()) {
                    hsv.v = rgb_matrix_get_val();
                }
                RGB rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
            }
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
