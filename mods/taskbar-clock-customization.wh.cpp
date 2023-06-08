// ==WindhawkMod==
// @id              taskbar-clock-customization
// @name            Taskbar Clock Customization
// @description     Customize the taskbar clock - add seconds, define a custom date/time format, add a news feed, and more
// @version         1.1.1
// @author          m417z
// @github          https://github.com/m417z
// @twitter         https://twitter.com/m417z
// @homepage        https://m417z.com/
// @include         explorer.exe
// @architecture    x86-64
// @compilerOptions -D__USE_MINGW_ANSI_STDIO=0 -lole32 -loleaut32 -lversion -lwininet
// ==/WindhawkMod==

// Source code is published under The GNU General Public License v3.0.
//
// For bug reports and feature requests, please open an issue here:
// https://github.com/ramensoftware/windhawk-mods/issues
//
// For pull requests, development takes place here:
// https://github.com/m417z/my-windhawk-mods

// ==WindhawkModReadme==
/*
# Taskbar Clock Customization

Customize the taskbar clock - add seconds, define a custom date/time format, add
a news feed, and more.

Only Windows 10 64-bit and Windows 11 are supported.

**Note:** To customize the old taskbar on Windows 11 (if using Explorer Patcher
or a similar tool), enable the relevant option in the mod's settings.

![Screenshot](https://i.imgur.com/gM9kbH5.png)

## Available patterns

Supported fields - top line, bottom line, middle line (Windows 10 only), tooltip
extra line - can be configured with text that contains patterns. The following
patterns can be used:

* `%time%` - the time as configured by the time format in settings.
* `%date%` - the date as configured by the date format in settings.
* `%weekday%` - the week day as configured by the week day format in settings.
* `%weekday_num%` - the week day number according to the [first day of
   week](https://superuser.com/q/61002) system configuration. For example, if
   first day of week is Sunday, then the week day number is 1 for Sunday, 2 for
   Monday, ..., 7 for Saturday.
* `%weeknum%` - the week number, calculated as following: The week containing 1
  January is defined as week 1 of the year. Subsequent weeks start on first day
  of week according to the system configuration.
* `%weeknum_iso%` - the [ISO week
  number](https://en.wikipedia.org/wiki/ISO_week_date).
* `%timezone%` - the time zone in ISO 8601 format.
* `%web%` - the web contents as configured in settings, truncated with ellipsis.
* `%web_full%` - the full web contents as configured in settings.

## Text styles

For Windows 11 version 22H2 and newer, the mod allows to change the clock text
styles, such as the font color and size.

![Screenshot](https://i.imgur.com/3JiXwjT.png)
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- ShowSeconds: true
  $name: Show seconds
- TimeFormat: >-
    hh':'mm':'ss tt
  $name: Time format
  $description: >-
    Leave empty for the default format, for syntax refer to the following page:

    https://docs.microsoft.com/en-us/windows/win32/api/datetimeapi/nf-datetimeapi-gettimeformatex#remarks
- DateFormat: >-
    ddd',' MMM dd yyyy
  $name: Date format
  $description: >-
    Leave empty for the default format, for syntax refer to the following page:

    https://docs.microsoft.com/en-us/windows/win32/intl/day--month--year--and-era-format-pictures
- WeekdayFormat: dddd
  $name: Week day format
  $description: >-
    Leave empty for the default format, for syntax refer to the following page:

    https://docs.microsoft.com/en-us/windows/win32/intl/day--month--year--and-era-format-pictures
- TopLine: '%date% | %time%'
  $name: Top line
  $description: >-
    Text to be shown on the first line, set to "-" for the default value, refer
    to the mod details for list of patterns that can be used
- BottomLine: '%web%'
  $name: Bottom line
  $description: >-
    Only shown if the taskbar is large enough, set to "-" for the default value
- MiddleLine: '%weekday%'
  $name: Middle line (Windows 10 only)
  $description: >-
    Only shown if the taskbar is large enough, set to "-" for the default value
- TooltipLine: '%web_full%'
  $name: Tooltip extra line
- Width: 180
  $name: Clock width (Windows 10 only)
- Height: 60
  $name: Clock height (Windows 10 only)
- TextSpacing: 0
  $name: Text spacing (Windows 10 only)
  $description: >-
    Set 0 for the default system value. A negative value can be used for
    negative spacing.
- WebContentsUrl: https://feeds.bbci.co.uk/news/world/rss.xml
  $name: Web content URL
  $description: >-
    Will be used to fetch data displayed in place of the %web% pattern
- WebContentsBlockStart: '<item>'
  $name: Web content block start
  $description: The string in the webpage to start from
- WebContentsStart: '<title><![CDATA['
  $name: Web content start
  $description: The string just before the content
- WebContentsEnd: ']]></title>'
  $name: Web content end
  $description: The string just after the content
- WebContentsMaxLength: 28
  $name: Web content maximum length
  $description: Longer strings will be truncated with ellipsis
- WebContentsUpdateInterval: 10
  $name: Web content update interval
  $description: The update interval, in minutes, of the web content
- TimeStyle:
  - Visible: true
  - TextColor: ""
    $name: Text color
    $description: >-
      Can be a color name (Red, Black, ...) or an RGB/ARGB color code (like
      #00FF00, #CC00FF00, ...)
  - FontSize: 0
    $name: Font size
    $description: Set to zero for the default size
  - FontFamily: ""
    $name: Font family
    $description: >-
      For a list of fonts that are shipped with Windows 11, refer to the
      following page:

      https://learn.microsoft.com/en-us/typography/fonts/windows_11_font_list
  - FontWeight: ""
    $name: Font weight
    $options:
    - "": Default
    - Thin: Thin
    - ExtraLight: Extra light
    - Light: Light
    - SemiLight: Semi light
    - Normal: Normal
    - Medium: Medium
    - SemiBold: Semi bold
    - Bold: Bold
    - ExtraBold: Extra bold
    - Black: Black
    - ExtraBlack: Extra black
  - FontStyle: ""
    $name: Font style
    $options:
    - "": Default
    - Normal: Normal
    - Oblique: Oblique
    - Italic: Italic
  - FontStretch: ""
    $name: Font stretch
    $description: Only supported for some fonts
    $options:
    - "": Default
    - Undefined: Undefined
    - UltraCondensed: Ultra condensed
    - ExtraCondensed: Extra condensed
    - Condensed: Condensed
    - SemiCondensed: Semi condensed
    - Normal: Normal
    - SemiExpanded: Semi expanded
    - Expanded: Expanded
    - ExtraExpanded: Extra expanded
    - UltraExpanded: Ultra expanded
  - CharacterSpacing: 0
    $name: Character spacing
    $description: Can be a positive or a negative number
  $name: Top line style (Windows 11 version 22H2 and newer)
  $description: Hover over the clock to apply the style
- DateStyle:
  - TextColor: ""
    $name: Text color
    $description: >-
      Can be a color name (Red, Black, ...) or an RGB/ARGB color code (like
      #00FF00, #CC00FF00, ...)
  - FontSize: 0
    $name: Font size
    $description: Set to zero for the default size
  - FontFamily: ""
    $name: Font family
    $description: >-
      For a list of fonts that are shipped with Windows 11, refer to the
      following page:

      https://learn.microsoft.com/en-us/typography/fonts/windows_11_font_list
  - FontWeight: ""
    $name: Font weight
    $options:
    - "": Default
    - Thin: Thin
    - ExtraLight: Extra light
    - Light: Light
    - SemiLight: Semi light
    - Normal: Normal
    - Medium: Medium
    - SemiBold: Semi bold
    - Bold: Bold
    - ExtraBold: Extra bold
    - Black: Black
    - ExtraBlack: Extra black
  - FontStyle: ""
    $name: Font style
    $options:
    - "": Default
    - Normal: Normal
    - Oblique: Oblique
    - Italic: Italic
  - FontStretch: ""
    $name: Font stretch
    $description: Only supported for some fonts
    $options:
    - "": Default
    - Undefined: Undefined
    - UltraCondensed: Ultra condensed
    - ExtraCondensed: Extra condensed
    - Condensed: Condensed
    - SemiCondensed: Semi condensed
    - Normal: Normal
    - SemiExpanded: Semi expanded
    - Expanded: Expanded
    - ExtraExpanded: Extra expanded
    - UltraExpanded: Ultra expanded
  - CharacterSpacing: 0
    $name: Character spacing
    $description: Can be a positive or a negative number
  $name: Bottom line style (Windows 11 version 22H2 and newer)
  $description: Hover over the clock to apply the style
- oldTaskbarOnWin11: false
  $name: Customize the old taskbar on Windows 11
  $description: >-
    Enable this option to customize the old taskbar on Windows 11 (if using
    Explorer Patcher or a similar tool). Note: For Windhawk versions older
    than 1.3, you have to disable and re-enable the mod to apply this option.
*/
// ==/WindhawkModSettings==

#include <algorithm>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

#include <initguid.h>  // must come before knownfolders.h

#include <knownfolders.h>
#include <shlobj.h>
#include <wininet.h>

#undef GetCurrentTime

#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <winrt/Windows.UI.Xaml.Markup.h>
#include <winrt/Windows.UI.Xaml.Media.h>

using namespace winrt::Windows::UI::Xaml;

class StringSetting {
   public:
    StringSetting() = default;
    StringSetting(PCWSTR valueName) : m_stringSetting(valueName) {}
    operator PCWSTR() const { return m_stringSetting.get(); }
    PCWSTR get() const { return m_stringSetting.get(); }

   private:
    // https://stackoverflow.com/a/51274008
    template <auto fn>
    struct deleter_from_fn {
        template <typename T>
        constexpr void operator()(T* arg) const {
            fn(arg);
        }
    };
    using string_setting_unique_ptr =
        std::unique_ptr<const WCHAR[], deleter_from_fn<Wh_FreeStringSetting>>;

    string_setting_unique_ptr m_stringSetting;
};

struct TextStyleSettings {
    std::optional<bool> visible;
    StringSetting textColor;
    int fontSize;
    StringSetting fontFamily;
    StringSetting fontWeight;
    StringSetting fontStyle;
    StringSetting fontStretch;
    int characterSpacing;
};

struct {
    bool showSeconds;
    StringSetting timeFormat;
    StringSetting dateFormat;
    StringSetting weekdayFormat;
    StringSetting topLine;
    StringSetting bottomLine;
    StringSetting middleLine;
    StringSetting tooltipLine;
    int width;
    int height;
    int textSpacing;
    StringSetting webContentsUrl;
    StringSetting webContentsBlockStart;
    StringSetting webContentsStart;
    StringSetting webContentsEnd;
    int webContentsMaxLength;
    int webContentsUpdateInterval;
    TextStyleSettings timeStyle;
    TextStyleSettings dateStyle;
    bool oldTaskbarOnWin11;
} g_settings;

#define FORMATTED_BUFFER_SIZE 256

enum class WinVersion {
    Unsupported,
    Win10,
    Win11,
    Win11_22H2,
};

WinVersion g_winVersion;
HANDLE g_webContentUpdateThread;
HANDLE g_webContentUpdateStopEvent;
WCHAR g_timeFormatted[FORMATTED_BUFFER_SIZE];
WCHAR g_dateFormatted[FORMATTED_BUFFER_SIZE];
WCHAR g_weekdayFormatted[FORMATTED_BUFFER_SIZE];
WCHAR g_weekdayNumFormatted[FORMATTED_BUFFER_SIZE];
WCHAR g_weeknumFormatted[FORMATTED_BUFFER_SIZE];
WCHAR g_weeknumIsoFormatted[FORMATTED_BUFFER_SIZE];
WCHAR g_timezoneFormatted[FORMATTED_BUFFER_SIZE];
WCHAR g_webContent[FORMATTED_BUFFER_SIZE];
WCHAR g_webContentFull[FORMATTED_BUFFER_SIZE];

using GetDpiForWindow_t = UINT(WINAPI*)(HWND hwnd);
GetDpiForWindow_t pGetDpiForWindow;

using GetLocalTime_t = decltype(&GetLocalTime);
GetLocalTime_t GetLocalTime_Original;

using GetTimeFormatEx_t = decltype(&GetTimeFormatEx);
GetTimeFormatEx_t GetTimeFormatEx_Original;

using GetDateFormatEx_t = decltype(&GetDateFormatEx);
GetDateFormatEx_t GetDateFormatEx_Original;

using GetDateFormatW_t = decltype(&GetDateFormatW);
GetDateFormatW_t GetDateFormatW_Original;

// cndate begin
WCHAR g_cndateFormatted[FORMATTED_BUFFER_SIZE];

// https://github.com/isee15/Lunar-Solar-Calendar-Converter/blob/master/C%3AC%2B%2B/LunarSolarConverter.c
int GetBitInt(int data, int length, int shift) {
    return (data & (((1 << length) - 1) << shift)) >> shift;
}

//WARNING: Dates before Oct. 1582 are inaccurate
long SolarToInt(int y, int m, int d) {
    m = (m + 9) % 12;
    y = y - m / 10;
    return 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1);
}

// 1890 - 2233
static int lunar_month_days[] = {1887, 0x1694, 0x16aa, 0x4ad5, 0xab6, 0xc4b7, 0x4ae, 0xa56, 0xb52a, 0x1d2a, 0xd54, 0x75aa, 0x156a, 0x1096d, 0x95c, 0x14ae, 0xaa4d, 0x1a4c, 0x1b2a, 0x8d55, 0xad4, 0x135a, 0x495d, 0x95c, 0xd49b, 0x149a, 0x1a4a, 0xbaa5, 0x16a8, 0x1ad4, 0x52da, 0x12b6, 0xe937, 0x92e, 0x1496, 0xb64b, 0xd4a, 0xda8, 0x95b5, 0x56c, 0x12ae, 0x492f, 0x92e, 0xcc96, 0x1a94, 0x1d4a, 0xada9, 0xb5a, 0x56c, 0x726e, 0x125c, 0xf92d, 0x192a, 0x1a94, 0xdb4a, 0x16aa, 0xad4, 0x955b, 0x4ba, 0x125a, 0x592b, 0x152a, 0xf695, 0xd94, 0x16aa, 0xaab5, 0x9b4, 0x14b6, 0x6a57, 0xa56, 0x1152a, 0x1d2a, 0xd54, 0xd5aa, 0x156a, 0x96c, 0x94ae, 0x14ae, 0xa4c, 0x7d26, 0x1b2a, 0xeb55, 0xad4, 0x12da, 0xa95d, 0x95a, 0x149a, 0x9a4d, 0x1a4a, 0x11aa5, 0x16a8, 0x16d4, 0xd2da, 0x12b6, 0x936, 0x9497, 0x1496, 0x1564b, 0xd4a, 0xda8, 0xd5b4, 0x156c, 0x12ae, 0xa92f, 0x92e, 0xc96, 0x6d4a, 0x1d4a, 0x10d65, 0xb58, 0x156c, 0xb26d, 0x125c, 0x192c, 0x9a95, 0x1a94, 0x1b4a, 0x4b55, 0xad4, 0xf55b, 0x4ba, 0x125a, 0xb92b, 0x152a, 0x1694, 0x96aa, 0x15aa, 0x12ab5, 0x974, 0x14b6, 0xca57, 0xa56, 0x1526, 0x8e95, 0xd54, 0x15aa, 0x49b5, 0x96c, 0xd4ae, 0x149c, 0x1a4c, 0xbd26, 0x1aa6, 0xb54, 0x6d6a, 0x12da, 0x1695d, 0x95a, 0x149a, 0xda4b, 0x1a4a, 0x1aa4, 0xbb54, 0x16b4, 0xada, 0x495b, 0x936, 0xf497, 0x1496, 0x154a, 0xb6a5, 0xda4, 0x15b4, 0x6ab6, 0x126e, 0x1092f, 0x92e, 0xc96, 0xcd4a, 0x1d4a, 0xd64, 0x956c, 0x155c, 0x125c, 0x792e, 0x192c, 0xfa95, 0x1a94, 0x1b4a, 0xab55, 0xad4, 0x14da, 0x8a5d, 0xa5a, 0x1152b, 0x152a, 0x1694, 0xd6aa, 0x15aa, 0xab4, 0x94ba, 0x14b6, 0xa56, 0x7527, 0xd26, 0xee53, 0xd54, 0x15aa, 0xa9b5, 0x96c, 0x14ae, 0x8a4e, 0x1a4c, 0x11d26, 0x1aa4, 0x1b54, 0xcd6a, 0xada, 0x95c, 0x949d, 0x149a, 0x1a2a, 0x5b25, 0x1aa4, 0xfb52, 0x16b4, 0xaba, 0xa95b, 0x936, 0x1496, 0x9a4b, 0x154a, 0x136a5, 0xda4, 0x15ac, 0xcab6, 0x126e, 0x92e, 0x8c97, 0xa96, 0xd4a, 0x6da5, 0xd54, 0xf56a, 0x155a, 0xa5c, 0xb92e, 0x152c, 0x1a94, 0x9d4a, 0x1b2a, 0x16b55, 0xad4, 0x14da, 0xca5d, 0xa5a, 0x151a, 0xba95, 0x1654, 0x16aa, 0x4ad5, 0xab4, 0xf4ba, 0x14b6, 0xa56, 0xb517, 0xd16, 0xe52, 0x96aa, 0xd6a, 0x165b5, 0x96c, 0x14ae, 0xca2e, 0x1a2c, 0x1d16, 0xad52, 0x1b52, 0xb6a, 0x656d, 0x55c, 0xf45d, 0x145a, 0x1a2a, 0xda95, 0x16a4, 0x1ad2, 0x8b5a, 0xab6, 0x1455b, 0x8b6, 0x1456, 0xd52b, 0x152a, 0x1694, 0xb6aa, 0x15aa, 0xab6, 0x64b7, 0x8ae, 0xec57, 0xa56, 0xd2a, 0xcd95, 0xb54, 0x156a, 0x8a6d, 0x95c, 0x14ae, 0x4a56, 0x1a54, 0xdd2a, 0x1aaa, 0xb54, 0xb56a, 0x14da, 0x95c, 0x74ab, 0x149a, 0xfa4b, 0x1652, 0x16aa, 0xcad5, 0x5b4, 0x12ba, 0x895b, 0x936, 0x13497, 0xc96, 0xd52, 0xd6a9, 0xd6a, 0x56c, 0x92b6, 0x126e, 0x92e, 0x6c96, 0x1c94, 0xfd4a, 0x1b52, 0xb6a, 0xa56d, 0x55c, 0x125c, 0x992d, 0x192a, 0x13a95, 0x1694, 0x16d2, 0xeada, 0xab6, 0x4ba, 0xb25b, 0x1256, 0x152a, 0x7a95, 0x1694, 0x116aa};
static int solar_1_1[] = {1887, 0xec04c, 0xec23f, 0xec435, 0xec649, 0xec83e, 0xeca51, 0xecc46, 0xece3a, 0xed04d, 0xed242, 0xed436, 0xed64a, 0xed83f, 0xeda53, 0xedc48, 0xede3d, 0xee050, 0xee244, 0xee439, 0xee64d, 0xee842, 0xeea36, 0xeec4a, 0xeee3e, 0xef052, 0xef246, 0xef43a, 0xef64e, 0xef843, 0xefa37, 0xefc4b, 0xefe41, 0xf0054, 0xf0248, 0xf043c, 0xf0650, 0xf0845, 0xf0a38, 0xf0c4d, 0xf0e42, 0xf1037, 0xf124a, 0xf143e, 0xf1651, 0xf1846, 0xf1a3a, 0xf1c4e, 0xf1e44, 0xf2038, 0xf224b, 0xf243f, 0xf2653, 0xf2848, 0xf2a3b, 0xf2c4f, 0xf2e45, 0xf3039, 0xf324d, 0xf3442, 0xf3636, 0xf384a, 0xf3a3d, 0xf3c51, 0xf3e46, 0xf403b, 0xf424e, 0xf4443, 0xf4638, 0xf484c, 0xf4a3f, 0xf4c52, 0xf4e48, 0xf503c, 0xf524f, 0xf5445, 0xf5639, 0xf584d, 0xf5a42, 0xf5c35, 0xf5e49, 0xf603e, 0xf6251, 0xf6446, 0xf663b, 0xf684f, 0xf6a43, 0xf6c37, 0xf6e4b, 0xf703f, 0xf7252, 0xf7447, 0xf763c, 0xf7850, 0xf7a45, 0xf7c39, 0xf7e4d, 0xf8042, 0xf8254, 0xf8449, 0xf863d, 0xf8851, 0xf8a46, 0xf8c3b, 0xf8e4f, 0xf9044, 0xf9237, 0xf944a, 0xf963f, 0xf9853, 0xf9a47, 0xf9c3c, 0xf9e50, 0xfa045, 0xfa238, 0xfa44c, 0xfa641, 0xfa836, 0xfaa49, 0xfac3d, 0xfae52, 0xfb047, 0xfb23a, 0xfb44e, 0xfb643, 0xfb837, 0xfba4a, 0xfbc3f, 0xfbe53, 0xfc048, 0xfc23c, 0xfc450, 0xfc645, 0xfc839, 0xfca4c, 0xfcc41, 0xfce36, 0xfd04a, 0xfd23d, 0xfd451, 0xfd646, 0xfd83a, 0xfda4d, 0xfdc43, 0xfde37, 0xfe04b, 0xfe23f, 0xfe453, 0xfe648, 0xfe83c, 0xfea4f, 0xfec44, 0xfee38, 0xff04c, 0xff241, 0xff436, 0xff64a, 0xff83e, 0xffa51, 0xffc46, 0xffe3a, 0x10004e, 0x100242, 0x100437, 0x10064b, 0x100841, 0x100a53, 0x100c48, 0x100e3c, 0x10104f, 0x101244, 0x101438, 0x10164c, 0x101842, 0x101a35, 0x101c49, 0x101e3d, 0x102051, 0x102245, 0x10243a, 0x10264e, 0x102843, 0x102a37, 0x102c4b, 0x102e3f, 0x103053, 0x103247, 0x10343b, 0x10364f, 0x103845, 0x103a38, 0x103c4c, 0x103e42, 0x104036, 0x104249, 0x10443d, 0x104651, 0x104846, 0x104a3a, 0x104c4e, 0x104e43, 0x105038, 0x10524a, 0x10543e, 0x105652, 0x105847, 0x105a3b, 0x105c4f, 0x105e45, 0x106039, 0x10624c, 0x106441, 0x106635, 0x106849, 0x106a3d, 0x106c51, 0x106e47, 0x10703c, 0x10724f, 0x107444, 0x107638, 0x10784c, 0x107a3f, 0x107c53, 0x107e48, 0x10803d, 0x108250, 0x108446, 0x10863a, 0x10884e, 0x108a42, 0x108c36, 0x108e4a, 0x10903e, 0x109251, 0x109447, 0x10963b, 0x10984f, 0x109a43, 0x109c37, 0x109e4b, 0x10a041, 0x10a253, 0x10a448, 0x10a63d, 0x10a851, 0x10aa45, 0x10ac39, 0x10ae4d, 0x10b042, 0x10b236, 0x10b44a, 0x10b63e, 0x10b852, 0x10ba47, 0x10bc3b, 0x10be4f, 0x10c044, 0x10c237, 0x10c44b, 0x10c641, 0x10c854, 0x10ca48, 0x10cc3d, 0x10ce50, 0x10d045, 0x10d239, 0x10d44c, 0x10d642, 0x10d837, 0x10da4a, 0x10dc3e, 0x10de52, 0x10e047, 0x10e23a, 0x10e44e, 0x10e643, 0x10e838, 0x10ea4b, 0x10ec41, 0x10ee54, 0x10f049, 0x10f23c, 0x10f450, 0x10f645, 0x10f839, 0x10fa4c, 0x10fc42, 0x10fe37, 0x11004b, 0x11023e, 0x110452, 0x110647, 0x11083b, 0x110a4e, 0x110c43, 0x110e38, 0x11104c, 0x11123f, 0x111435, 0x111648, 0x11183c, 0x111a4f, 0x111c45, 0x111e39, 0x11204d, 0x112242, 0x112436, 0x11264a, 0x11283e, 0x112a51, 0x112c46, 0x112e3b, 0x11304f, 0x113244, 0x113439, 0x11364d, 0x113842, 0x113a54, 0x113c49, 0x113e3d, 0x114051, 0x114246, 0x11443a, 0x11464e, 0x114844, 0x114a37, 0x114c4a, 0x114e3e, 0x115052, 0x115247, 0x11543c, 0x115650, 0x115845, 0x115a38, 0x115c4c, 0x115e41, 0x116054, 0x116248, 0x11643d, 0x116651, 0x116847, 0x116a3a, 0x116c4e, 0x116e43, 0x117037, 0x11724a, 0x11743e};
static WCHAR lunar_month_name[][3] = { L"正月", L"二月", L"三月", L"四月", L"五月", L"六月", L"七月", L"八月", L"九月", L"十月", L"冬月", L"腊月" };
static WCHAR lunar_day_name[][3] = { L"初一", L"初二", L"初三", L"初四", L"初五", L"初六", L"初七", L"初八", L"初九", L"初十", L"十一", L"十二", L"十三", L"十四", L"十五", L"十六", L"十七", L"十八", L"十九", L"二十", L"廿一", L"廿二", L"廿三", L"廿四", L"廿五", L"廿六", L"廿七", L"廿八", L"廿九", L"三十" };

void GetCNDate(const SYSTEMTIME* time) {
    int index = time->wYear - solar_1_1[0];
    int data = (time->wYear << 9) | (time->wMonth << 5) | (time->wDay);
    int solar11 = 0;
    if (solar_1_1[index] > data) {
        index--;
    }
    solar11 = solar_1_1[index];
    int y = GetBitInt(solar11, 12, 9);
    int m = GetBitInt(solar11, 4, 5);
    int d = GetBitInt(solar11, 5, 0);
    long offset = SolarToInt(time->wYear, time->wMonth, time->wDay) - SolarToInt(y, m, d);

    int days = lunar_month_days[index];
    int leap = GetBitInt(days, 4, 13);

    int lunarY = index + solar_1_1[0];
    int lunarM = 1;
    int lunarD;
	bool isleap = false;
    offset += 1;

    for (int i = 0; i < 13; i++) {
        int dm = GetBitInt(days, 1, 12 - i) == 1 ? 30 : 29;
        if (offset > dm) {
            lunarM++;
            offset -= dm;
        }
        else {
            break;
        }
    }
    lunarD = (int) (offset);
    if (leap != 0 && lunarM > leap) {
        if (lunarM == leap + 1) {
            isleap = true;
        }
        lunarM = lunarM - 1;
    }

	_snwprintf_s(g_cndateFormatted, ARRAYSIZE(g_cndateFormatted), _TRUNCATE, (isleap ? L"闰%s%s" : L"%s%s"), lunar_month_name[lunarM-1], lunar_day_name[lunarD-1]);
}
// cndate end

LPBYTE GetUrlContent(PCWSTR lpUrl, LPDWORD pdwLength) {
    HINTERNET hOpenHandle, hUrlHandle;
    LPBYTE pUrlContent;
    DWORD dwLength, dwNumberOfBytesRead;

    hOpenHandle =
        InternetOpen(L"TaskbarClockCustomization", INTERNET_OPEN_TYPE_PRECONFIG,
                     nullptr, nullptr, 0);
    if (hOpenHandle == nullptr) {
        return nullptr;
    }

    hUrlHandle =
        InternetOpenUrl(hOpenHandle, lpUrl, nullptr, 0,
                        INTERNET_FLAG_NO_AUTH | INTERNET_FLAG_NO_CACHE_WRITE |
                            INTERNET_FLAG_NO_COOKIES | INTERNET_FLAG_NO_UI |
                            INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_RELOAD,
                        0);
    if (hUrlHandle == nullptr) {
        InternetCloseHandle(hOpenHandle);
        return nullptr;
    }

    pUrlContent = (LPBYTE)HeapAlloc(GetProcessHeap(), 0, 0x400);
    if (pUrlContent) {
        InternetReadFile(hUrlHandle, pUrlContent, 0x400, &dwNumberOfBytesRead);
        dwLength = dwNumberOfBytesRead;

        while (dwNumberOfBytesRead) {
            LPBYTE pNewUrlContent = (LPBYTE)HeapReAlloc(
                GetProcessHeap(), 0, pUrlContent, dwLength + 0x400);
            if (!pNewUrlContent) {
                break;
            }

            pUrlContent = pNewUrlContent;
            InternetReadFile(hUrlHandle, pUrlContent + dwLength, 0x400,
                             &dwNumberOfBytesRead);
            dwLength += dwNumberOfBytesRead;
        }
    }

    InternetCloseHandle(hUrlHandle);
    InternetCloseHandle(hOpenHandle);

    if (pdwLength) {
        *pdwLength = dwLength;
    }

    return pUrlContent;
}

void FreeUrlContent(LPBYTE pUrlContent) {
    HeapFree(GetProcessHeap(), 0, pUrlContent);
}

int StringCopyTruncated(PWSTR dest,
                        size_t destSize,
                        PCWSTR src,
                        bool* truncated) {
    if (destSize == 0) {
        *truncated = *src;
        return 0;
    }

    size_t i;
    for (i = 0; i < destSize - 1 && *src; i++) {
        *dest++ = *src++;
    }

    *dest = L'\0';
    *truncated = *src;
    return i;
}

bool UpdateWebContent() {
    DWORD dwLength;
    LPBYTE pUrlContent = GetUrlContent(g_settings.webContentsUrl, &dwLength);
    if (!pUrlContent) {
        return false;
    }

    // Assume UTF-8.
    PWSTR unicodeContent = new WCHAR[dwLength + 1];
    DWORD dw = MultiByteToWideChar(CP_UTF8, 0, (PCSTR)pUrlContent, dwLength,
                                   unicodeContent, dwLength * 2);
    unicodeContent[dw] = L'\0';

    FreeUrlContent(pUrlContent);

    PWSTR block = wcsstr(unicodeContent, g_settings.webContentsBlockStart);
    if (block) {
        PWSTR start = wcsstr(block, g_settings.webContentsStart);
        if (start) {
            start += wcslen(g_settings.webContentsStart);

            PWSTR end = wcsstr(start, g_settings.webContentsEnd);
            if (end) {
                *end = L'\0';

                int maxLen = ARRAYSIZE(g_webContent) - 1;
                if (g_settings.webContentsMaxLength < maxLen) {
                    maxLen = g_settings.webContentsMaxLength;
                }

                bool truncated;
                StringCopyTruncated(g_webContent, maxLen + 1, start,
                                    &truncated);
                if (truncated && maxLen >= 3) {
                    g_webContent[maxLen - 1] = L'.';
                    g_webContent[maxLen - 2] = L'.';
                    g_webContent[maxLen - 3] = L'.';
                }

                maxLen = ARRAYSIZE(g_webContentFull) - 1;
                StringCopyTruncated(g_webContentFull, maxLen + 1, start,
                                    &truncated);
                if (truncated && maxLen >= 3) {
                    g_webContentFull[maxLen - 1] = L'.';
                    g_webContentFull[maxLen - 2] = L'.';
                    g_webContentFull[maxLen - 3] = L'.';
                }
            }
        }
    }

    delete[] unicodeContent;

    return true;
}

DWORD WINAPI WebContentUpdateThread(LPVOID lpThreadParameter) {
    constexpr DWORD kSecondsForQuickRetry = 30;

    while (true) {
        bool succeeded = UpdateWebContent();

        DWORD seconds = g_settings.webContentsUpdateInterval * 60;
        if (!succeeded && seconds > kSecondsForQuickRetry) {
            seconds = kSecondsForQuickRetry;
        }

        DWORD dwWaitResult =
            WaitForSingleObject(g_webContentUpdateStopEvent, seconds * 1000);
        if (dwWaitResult != WAIT_TIMEOUT) {
            break;
        }
    }

    return 0;
}

void WebContentUpdateThreadInit() {
    *g_webContent = L'\0';
    *g_webContentFull = L'\0';
    if (*g_settings.webContentsUrl) {
        g_webContentUpdateStopEvent =
            CreateEvent(nullptr, TRUE, FALSE, nullptr);
        g_webContentUpdateThread = CreateThread(
            nullptr, 0, WebContentUpdateThread, nullptr, 0, nullptr);
    }
}

void WebContentUpdateThreadUninit() {
    if (g_webContentUpdateThread) {
        SetEvent(g_webContentUpdateStopEvent);
        WaitForSingleObject(g_webContentUpdateThread, INFINITE);
        CloseHandle(g_webContentUpdateThread);
        g_webContentUpdateThread = nullptr;
        CloseHandle(g_webContentUpdateStopEvent);
        g_webContentUpdateStopEvent = nullptr;
    }
}

int CalculateWeeknum(const SYSTEMTIME* time, DWORD startDayOfWeek) {
    SYSTEMTIME secondWeek{
        .wYear = time->wYear,
        .wMonth = 1,
        .wDay = 1,
    };

    // Calculate wDayOfWeek.
    FILETIME fileTime;
    SystemTimeToFileTime(&secondWeek, &fileTime);
    FileTimeToSystemTime(&fileTime, &secondWeek);

    do {
        secondWeek.wDay++;
        secondWeek.wDayOfWeek = (secondWeek.wDayOfWeek + 1) % 7;
    } while (secondWeek.wDayOfWeek != startDayOfWeek);

    FILETIME targetFileTime;
    SystemTimeToFileTime(time, &targetFileTime);
    ULARGE_INTEGER targetFileTimeInt{
        .LowPart = targetFileTime.dwLowDateTime,
        .HighPart = targetFileTime.dwHighDateTime,
    };

    FILETIME secondWeekFileTime;
    SystemTimeToFileTime(&secondWeek, &secondWeekFileTime);
    ULARGE_INTEGER secondWeekFileTimeInt{
        .LowPart = secondWeekFileTime.dwLowDateTime,
        .HighPart = secondWeekFileTime.dwHighDateTime,
    };

    int weeknum = 1;
    if (targetFileTimeInt.QuadPart >= secondWeekFileTimeInt.QuadPart) {
        ULONGLONG diff =
            targetFileTimeInt.QuadPart - secondWeekFileTimeInt.QuadPart;
        ULONGLONG weekIn100Ns = 10000000ULL * 60 * 60 * 24 * 7;
        weeknum += 1 + diff / weekIn100Ns;
    }

    return weeknum;
}

// Adopted from VMime:
// https://github.com/kisli/vmime/blob/fc69321d5304c73be685c890f3b30528aadcfeaf/src/vmime/utility/datetimeUtils.cpp#L239
int CalculateWeeknumIso(const SYSTEMTIME* time) {
    const int year = time->wYear;
    const int month = time->wMonth;
    const int day = time->wDay;
    const bool iso = true;

    // Algorithm from http://personal.ecu.edu/mccartyr/ISOwdALG.txt

    const bool leapYear =
        ((year % 4) == 0 && (year % 100) != 0) || (year % 400) == 0;
    const bool leapYear_1 =
        (((year - 1) % 4) == 0 && ((year - 1) % 100) != 0) ||
        ((year - 1) % 400) == 0;

    // 4. Find the DayOfYearNumber for Y M D
    static const int DAY_OF_YEAR_NUMBER_MAP[12] = {
        0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

    int DayOfYearNumber = day + DAY_OF_YEAR_NUMBER_MAP[month - 1];

    if (leapYear && month > 2) {
        DayOfYearNumber += 1;
    }

    // 5. Find the Jan1Weekday for Y (Monday=1, Sunday=7)
    const int YY = (year - 1) % 100;
    const int C = (year - 1) - YY;
    const int G = YY + YY / 4;
    const int Jan1Weekday = 1 + (((((C / 100) % 4) * 5) + G) % 7);

    // 6. Find the Weekday for Y M D
    const int H = DayOfYearNumber + (Jan1Weekday - 1);
    const int Weekday = 1 + ((H - 1) % 7);

    // 7. Find if Y M D falls in YearNumber Y-1, WeekNumber 52 or 53
    int YearNumber = 0, WeekNumber = 0;

    if (DayOfYearNumber <= (8 - Jan1Weekday) && Jan1Weekday > 4) {
        YearNumber = year - 1;

        if (Jan1Weekday == 5 || (Jan1Weekday == 6 && leapYear_1)) {
            WeekNumber = 53;
        } else {
            WeekNumber = 52;
        }

    } else {
        YearNumber = year;
    }

    // 8. Find if Y M D falls in YearNumber Y+1, WeekNumber 1
    if (YearNumber == year) {
        const int I = (leapYear ? 366 : 365);

        if ((I - DayOfYearNumber) < (4 - Weekday)) {
            YearNumber = year + 1;
            WeekNumber = 1;
        }
    }

    // 9. Find if Y M D falls in YearNumber Y, WeekNumber 1 through 53
    if (YearNumber == year) {
        const int J = DayOfYearNumber + (7 - Weekday) + (Jan1Weekday - 1);

        WeekNumber = J / 7;

        if (Jan1Weekday > 4) {
            WeekNumber -= 1;
        }
    }

    if (!iso && (WeekNumber == 1 && month == 12)) {
        WeekNumber = 53;
    }

    return WeekNumber;
}

// Adopted from:
// https://github.com/microsoft/cpp_client_telemetry/blob/25bc0806f21ecb2587154494f073bfa581cd5089/lib/pal/desktop/WindowsEnvironmentInfo.hpp#L39
void GetTimeZone(WCHAR* buffer, size_t bufferSize) {
    long bias;

    TIME_ZONE_INFORMATION timeZone = {};
    if (GetTimeZoneInformation(&timeZone) == TIME_ZONE_ID_DAYLIGHT) {
        bias = timeZone.Bias + timeZone.DaylightBias;
    } else {
        // TODO: [MG] - ref.
        // https://docs.microsoft.com/en-us/windows/win32/api/timezoneapi/nf-timezoneapi-gettimezoneinformation
        // Need to handle the case when API return TIME_ZONE_ID_UNKNOWN.
        // Otherwise we may be reporting invalid timeZone.Bias
        bias = timeZone.Bias + timeZone.StandardBias;
    }

    auto hours = (long long)abs(bias) / 60;
    auto minutes = (long long)abs(bias) % 60;

    // UTC = local time + bias; bias sign should be interved.
    _snwprintf_s(buffer, bufferSize, _TRUNCATE, L"%c%02d:%02d",
                 bias <= 0 ? L'+' : L'-', static_cast<int>(hours),
                 static_cast<int>(minutes));
}

void InitializeFormattedStrings(const SYSTEMTIME* time) {
    GetTimeFormatEx_Original(
        nullptr, g_settings.showSeconds ? 0 : TIME_NOSECONDS, time,
        *g_settings.timeFormat ? g_settings.timeFormat.get() : nullptr,
        g_timeFormatted, ARRAYSIZE(g_timeFormatted));
    GetDateFormatEx_Original(
        nullptr, DATE_AUTOLAYOUT, time,
        *g_settings.dateFormat ? g_settings.dateFormat.get() : nullptr,
        g_dateFormatted, ARRAYSIZE(g_dateFormatted), nullptr);
    GetDateFormatEx_Original(
        nullptr, DATE_AUTOLAYOUT, time,
        *g_settings.weekdayFormat ? g_settings.weekdayFormat.get() : nullptr,
        g_weekdayFormatted, ARRAYSIZE(g_weekdayFormatted), nullptr);

    // https://stackoverflow.com/a/39344961
    DWORD startDayOfWeek;
    GetLocaleInfoEx(
        LOCALE_NAME_USER_DEFAULT, LOCALE_IFIRSTDAYOFWEEK | LOCALE_RETURN_NUMBER,
        (PWSTR)&startDayOfWeek, sizeof(startDayOfWeek) / sizeof(WCHAR));

    // Start from Sunday instead of Monday.
    startDayOfWeek = (startDayOfWeek + 1) % 7;

    swprintf_s(g_weekdayNumFormatted, L"%d",
               1 + (7 + time->wDayOfWeek - startDayOfWeek) % 7);

    swprintf_s(g_weeknumFormatted, L"%d",
               CalculateWeeknum(time, startDayOfWeek));

    swprintf_s(g_weeknumIsoFormatted, L"%d", CalculateWeeknumIso(time));

    GetTimeZone(g_timezoneFormatted, ARRAYSIZE(g_timezoneFormatted));
    
    // cndate
    GetCNDate(time);
}

int FormatLine(PWSTR buffer, size_t bufferSize, PCWSTR format) {
    if (bufferSize == 0) {
        return 0;
    }

    PWSTR bufferStart = buffer;
    PWSTR bufferEnd = bufferStart + bufferSize;
    while (*format && bufferEnd - buffer > 1) {
        if (*format == L'%') {
            PCWSTR srcStr = nullptr;
            size_t formatTokenLen;

            if (wcsncmp(L"%time%", format, sizeof("%time%") - 1) == 0) {
                srcStr = g_timeFormatted;
                formatTokenLen = sizeof("%time%") - 1;
            } else if (wcsncmp(L"%date%", format, sizeof("%date%") - 1) == 0) {
                srcStr = g_dateFormatted;
                formatTokenLen = sizeof("%date%") - 1;
            } else if (wcsncmp(L"%weekday%", format, sizeof("%weekday%") - 1) ==
                       0) {
                srcStr = g_weekdayFormatted;
                formatTokenLen = sizeof("%weekday%") - 1;
            } else if (wcsncmp(L"%weekday_num%", format,
                               sizeof("%weekday_num%") - 1) == 0) {
                srcStr = g_weekdayNumFormatted;
                formatTokenLen = sizeof("%weekday_num%") - 1;
            } else if (wcsncmp(L"%weeknum%", format, sizeof("%weeknum%") - 1) ==
                       0) {
                srcStr = g_weeknumFormatted;
                formatTokenLen = sizeof("%weeknum%") - 1;
            } else if (wcsncmp(L"%weeknum_iso%", format,
                               sizeof("%weeknum_iso%") - 1) == 0) {
                srcStr = g_weeknumIsoFormatted;
                formatTokenLen = sizeof("%weeknum_iso%") - 1;
            } else if (wcsncmp(L"%timezone%", format,
                               sizeof("%timezone%") - 1) == 0) {
                srcStr = g_timezoneFormatted;
                formatTokenLen = sizeof("%timezone%") - 1;
            } else if (wcsncmp(L"%web%", format, sizeof("%web%") - 1) == 0) {
                srcStr = *g_webContent ? g_webContent : L"Loading...";
                formatTokenLen = sizeof("%web%") - 1;
            } else if (wcsncmp(L"%web_full%", format,
                               sizeof("%web_full%") - 1) == 0) {
                srcStr = *g_webContentFull ? g_webContentFull : L"Loading...";
                formatTokenLen = sizeof("%web_full%") - 1;
            } else if (wcsncmp(L"%cndate%", format, sizeof("%cndate%") - 1) == 0) {
                srcStr = g_cndateFormatted;
                formatTokenLen = sizeof("%cndate%") - 1;
            } // cndate

            if (srcStr) {
                bool truncated;
                buffer += StringCopyTruncated(buffer, bufferEnd - buffer,
                                              srcStr, &truncated);
                if (truncated) {
                    break;
                }

                format += formatTokenLen;
                continue;
            }
        }

        *buffer++ = *format++;
    }

    if (*format && bufferSize >= 4) {
        buffer[-1] = L'.';
        buffer[-2] = L'.';
        buffer[-3] = L'.';
    }

    *buffer = L'\0';

    return buffer - bufferStart;
}

#pragma region Win11Hooks

DWORD g_refreshIconThreadId;
bool g_refreshIconNeedToAdjustTimer;
bool g_inGetTimeToolTipString;

using ClockSystemTrayIconDataModel_RefreshIcon_t = void(WINAPI*)(
    LPVOID pThis,
    LPVOID  // SystemTrayTelemetry::ClockUpdate&
);
ClockSystemTrayIconDataModel_RefreshIcon_t
    ClockSystemTrayIconDataModel_RefreshIcon_Original;

using ClockSystemTrayIconDataModel_GetTimeToolTipString_t =
    LPVOID(WINAPI*)(LPVOID pThis, LPVOID, LPVOID, LPVOID, LPVOID);
ClockSystemTrayIconDataModel_GetTimeToolTipString_t
    ClockSystemTrayIconDataModel_GetTimeToolTipString_Original;

using DateTimeIconContent_OnApplyTemplate_t = void(WINAPI*)(LPVOID pThis);
DateTimeIconContent_OnApplyTemplate_t
    DateTimeIconContent_OnApplyTemplate_Original;

using DateTimeIconContent_OnPointerEntered_t = void(WINAPI*)(LPVOID pThis,
                                                             LPVOID pArgs);
DateTimeIconContent_OnPointerEntered_t
    DateTimeIconContent_OnPointerEntered_Original;

void* DateTimeIconContent_vftable;

using ClockSystemTrayIconDataModel_GetTimeToolTipString_2_t =
    LPVOID(WINAPI*)(LPVOID pThis, LPVOID, LPVOID, LPVOID, LPVOID);
ClockSystemTrayIconDataModel_GetTimeToolTipString_2_t
    ClockSystemTrayIconDataModel_GetTimeToolTipString_2_Original;

using ICalendar_Second_t = int(WINAPI*)(LPVOID pThis);
ICalendar_Second_t ICalendar_Second_Original;

void WINAPI ClockSystemTrayIconDataModel_RefreshIcon_Hook(LPVOID pThis,
                                                          LPVOID param1) {
    Wh_Log(L">");

    g_refreshIconThreadId = GetCurrentThreadId();
    g_refreshIconNeedToAdjustTimer = g_settings.showSeconds || !*g_webContent;

    ClockSystemTrayIconDataModel_RefreshIcon_Original(pThis, param1);

    g_refreshIconThreadId = 0;
    g_refreshIconNeedToAdjustTimer = false;
}

void UpdateToolTipString(LPVOID tooltipPtrPtr) {
    std::wstring_view separator = L"\r\n\r\n";

    WCHAR extraLine[256];
    size_t extraLength =
        FormatLine(extraLine, ARRAYSIZE(extraLine), g_settings.tooltipLine);
    if (extraLength == 0) {
        return;
    }

    // Reference:
    // https://github.com/microsoft/cppwinrt/blob/0a6cb062e2151cf6c8f357aa8ef735e359f8a98c/strings/base_string.h
    struct hstring_header {
        uint32_t flags;
        uint32_t length;
        uint32_t padding1;
        uint32_t padding2;
        wchar_t const* ptr;
    };

    struct shared_hstring_header : hstring_header {
        int32_t /*atomic_ref_count*/ count;
        wchar_t buffer[1];
    };

    shared_hstring_header* tooltipHeader =
        *(shared_hstring_header**)tooltipPtrPtr;

    uint64_t bytesRequired =
        sizeof(shared_hstring_header) +
        sizeof(wchar_t) *
            (tooltipHeader->length + separator.length() + extraLength);

    shared_hstring_header* tooltipHeaderNew =
        (shared_hstring_header*)HeapReAlloc(GetProcessHeap(), 0, tooltipHeader,
                                            bytesRequired);
    if (!tooltipHeaderNew) {
        return;
    }

    tooltipHeaderNew->ptr = tooltipHeaderNew->buffer;

    memcpy(tooltipHeaderNew->buffer + tooltipHeaderNew->length,
           separator.data(), sizeof(wchar_t) * separator.length());
    tooltipHeaderNew->length += separator.length();

    memcpy(tooltipHeaderNew->buffer + tooltipHeaderNew->length, extraLine,
           sizeof(wchar_t) * extraLength);
    tooltipHeaderNew->length += extraLength;

    tooltipHeaderNew->buffer[tooltipHeaderNew->length] = L'\0';

    *(shared_hstring_header**)tooltipPtrPtr = tooltipHeaderNew;
}

LPVOID WINAPI
ClockSystemTrayIconDataModel_GetTimeToolTipString_Hook(LPVOID pThis,
                                                       LPVOID param1,
                                                       LPVOID param2,
                                                       LPVOID param3,
                                                       LPVOID param4) {
    Wh_Log(L">");

    g_inGetTimeToolTipString = true;

    LPVOID ret = ClockSystemTrayIconDataModel_GetTimeToolTipString_Original(
        pThis, param1, param2, param3, param4);

    UpdateToolTipString(ret);

    g_inGetTimeToolTipString = false;

    return ret;
}

FrameworkElement FindChildByName(FrameworkElement element,
                                 winrt::hstring name) {
    int childrenCount = Media::VisualTreeHelper::GetChildrenCount(element);

    for (int i = 0; i < childrenCount; i++) {
        auto child = Media::VisualTreeHelper::GetChild(element, i)
                         .try_as<FrameworkElement>();
        if (!child) {
            Wh_Log(L"Failed to get child %d of %d", i + 1, childrenCount);
            continue;
        }

        if (child.Name() == name) {
            return child;
        }
    }

    return nullptr;
}

void ApplyTextBlockStyles(Controls::TextBlock textBlock,
                          const TextStyleSettings& textStyleSettings) {
    if (textStyleSettings.visible) {
        if (!*textStyleSettings.visible) {
            textBlock.Visibility(Visibility::Collapsed);
            return;
        }

        textBlock.Visibility(Visibility::Visible);
    }

    if (*textStyleSettings.textColor) {
        auto textColor =
            Markup::XamlBindingHelper::ConvertValue(
                winrt::xaml_typename<winrt::Windows::UI::Color>(),
                winrt::box_value(textStyleSettings.textColor.get()))
                .as<winrt::Windows::UI::Color>();
        textBlock.Foreground(Media::SolidColorBrush{textColor});
    } else {
        textBlock.as<DependencyObject>().ClearValue(
            Controls::TextBlock::ForegroundProperty());
    }

    if (textStyleSettings.fontSize) {
        textBlock.FontSize(textStyleSettings.fontSize);
    } else {
        textBlock.as<DependencyObject>().ClearValue(
            Controls::TextBlock::FontSizeProperty());
    }

    if (*textStyleSettings.fontFamily) {
        auto fontFamily =
            Markup::XamlBindingHelper::ConvertValue(
                winrt::xaml_typename<Media::FontFamily>(),
                winrt::box_value(textStyleSettings.fontFamily.get()))
                .as<Media::FontFamily>();
        textBlock.FontFamily(fontFamily);
    } else {
        textBlock.as<DependencyObject>().ClearValue(
            Controls::TextBlock::FontFamilyProperty());
    }

    if (*textStyleSettings.fontWeight) {
        auto fontWeight =
            Markup::XamlBindingHelper::ConvertValue(
                winrt::xaml_typename<winrt::Windows::UI::Text::FontWeight>(),
                winrt::box_value(textStyleSettings.fontWeight.get()))
                .as<winrt::Windows::UI::Text::FontWeight>();
        textBlock.FontWeight(fontWeight);
    } else {
        textBlock.as<DependencyObject>().ClearValue(
            Controls::TextBlock::FontWeightProperty());
    }

    if (*textStyleSettings.fontStyle) {
        auto fontStyle =
            Markup::XamlBindingHelper::ConvertValue(
                winrt::xaml_typename<winrt::Windows::UI::Text::FontStyle>(),
                winrt::box_value(textStyleSettings.fontStyle.get()))
                .as<winrt::Windows::UI::Text::FontStyle>();
        textBlock.FontStyle(fontStyle);
    } else {
        textBlock.as<DependencyObject>().ClearValue(
            Controls::TextBlock::FontStyleProperty());
    }

    if (*textStyleSettings.fontStretch) {
        auto fontStretch =
            Markup::XamlBindingHelper::ConvertValue(
                winrt::xaml_typename<winrt::Windows::UI::Text::FontStretch>(),
                winrt::box_value(textStyleSettings.fontStretch.get()))
                .as<winrt::Windows::UI::Text::FontStretch>();
        textBlock.FontStretch(fontStretch);
    } else {
        textBlock.as<DependencyObject>().ClearValue(
            Controls::TextBlock::FontStretchProperty());
    }

    if (textStyleSettings.characterSpacing) {
        textBlock.CharacterSpacing(textStyleSettings.characterSpacing);
    } else {
        textBlock.as<DependencyObject>().ClearValue(
            Controls::TextBlock::CharacterSpacingProperty());
    }
}

void ApplyDateTimeIconContentStyles(
    FrameworkElement dateTimeIconContentElement) {
    auto containerGridElement =
        FindChildByName(dateTimeIconContentElement, L"ContainerGrid")
            .as<Controls::Grid>();
    if (!containerGridElement) {
        return;
    }

    auto stackPanelChildren = containerGridElement.Children()
                                  .GetAt(0)
                                  .as<Controls::StackPanel>()
                                  .Children();

    Controls::TextBlock dateInnerTextBlock;
    Controls::TextBlock timeInnerTextBlock;

    for (const auto& child : stackPanelChildren) {
        auto childTextBlock = child.try_as<Controls::TextBlock>();
        if (!childTextBlock) {
            continue;
        }

        if (childTextBlock.Name() == L"DateInnerTextBlock") {
            dateInnerTextBlock = childTextBlock;
            continue;
        }

        if (childTextBlock.Name() == L"TimeInnerTextBlock") {
            timeInnerTextBlock = childTextBlock;
            continue;
        }
    }

    if (dateInnerTextBlock) {
        ApplyTextBlockStyles(dateInnerTextBlock, g_settings.dateStyle);
    }

    if (timeInnerTextBlock) {
        ApplyTextBlockStyles(timeInnerTextBlock, g_settings.timeStyle);
    }
}

void WINAPI DateTimeIconContent_OnApplyTemplate_Hook(LPVOID pThis) {
    Wh_Log(L">");

    DateTimeIconContent_OnApplyTemplate_Original(pThis);

    IUnknown* dateTimeIconContentElementIUnknownPtr = *((IUnknown**)pThis + 1);
    if (!dateTimeIconContentElementIUnknownPtr) {
        return;
    }

    FrameworkElement dateTimeIconContentElement = nullptr;
    dateTimeIconContentElementIUnknownPtr->QueryInterface(
        winrt::guid_of<FrameworkElement>(),
        winrt::put_abi(dateTimeIconContentElement));
    if (!dateTimeIconContentElement) {
        return;
    }

    try {
        ApplyDateTimeIconContentStyles(dateTimeIconContentElement);
    } catch (...) {
        HRESULT hr = winrt::to_hresult();
        Wh_Log(L"Error %08X", hr);
    }
}

void WINAPI DateTimeIconContent_OnPointerEntered_Hook(LPVOID pThis,
                                                      LPVOID pArgs) {
    Wh_Log(L">");

    DateTimeIconContent_OnPointerEntered_Original(pThis, pArgs);

    if (!DateTimeIconContent_vftable ||
        *(void**)pThis != DateTimeIconContent_vftable) {
        return;
    }

    IUnknown* dateTimeIconContentElementIUnknownPtr = *((IUnknown**)pThis + 1);
    if (!dateTimeIconContentElementIUnknownPtr) {
        return;
    }

    FrameworkElement dateTimeIconContentElement = nullptr;
    dateTimeIconContentElementIUnknownPtr->QueryInterface(
        winrt::guid_of<FrameworkElement>(),
        winrt::put_abi(dateTimeIconContentElement));
    if (!dateTimeIconContentElement) {
        return;
    }

    try {
        ApplyDateTimeIconContentStyles(dateTimeIconContentElement);
    } catch (...) {
        HRESULT hr = winrt::to_hresult();
        Wh_Log(L"Error %08X", hr);
    }
}

LPVOID WINAPI
ClockSystemTrayIconDataModel_GetTimeToolTipString_2_Hook(LPVOID pThis,
                                                         LPVOID param1,
                                                         LPVOID param2,
                                                         LPVOID param3,
                                                         LPVOID param4) {
    Wh_Log(L">");

    g_inGetTimeToolTipString = true;

    LPVOID ret = ClockSystemTrayIconDataModel_GetTimeToolTipString_2_Original(
        pThis, param1, param2, param3, param4);

    UpdateToolTipString(ret);

    g_inGetTimeToolTipString = false;

    return ret;
}

int WINAPI ICalendar_Second_Hook(LPVOID pThis) {
    Wh_Log(L">");

    if (g_refreshIconThreadId == GetCurrentThreadId() &&
        !g_inGetTimeToolTipString && g_refreshIconNeedToAdjustTimer) {
        g_refreshIconNeedToAdjustTimer = false;

        // Make the next refresh happen in a second.
        return 59;
    }

    int ret = ICalendar_Second_Original(pThis);

    return ret;
}

VOID WINAPI GetLocalTime_Hook_Win11(LPSYSTEMTIME lpSystemTime) {
    Wh_Log(L">");

    if (g_refreshIconThreadId == GetCurrentThreadId() &&
        !g_inGetTimeToolTipString && g_refreshIconNeedToAdjustTimer) {
        g_refreshIconNeedToAdjustTimer = false;

        // Make the next refresh happen in a second.
        memset(lpSystemTime, 0, sizeof(*lpSystemTime));
        lpSystemTime->wSecond = 59;
        return;
    }

    GetLocalTime_Original(lpSystemTime);
}

int WINAPI GetTimeFormatEx_Hook_Win11(LPCWSTR lpLocaleName,
                                      DWORD dwFlags,
                                      CONST SYSTEMTIME* lpTime,
                                      LPCWSTR lpFormat,
                                      LPWSTR lpTimeStr,
                                      int cchTime) {
    if (g_refreshIconThreadId == GetCurrentThreadId() &&
        !g_inGetTimeToolTipString) {
        if (wcscmp(g_settings.topLine, L"-") != 0) {
            if (!cchTime) {
                // Hopefully a large enough buffer size.
                return FORMATTED_BUFFER_SIZE;
            }

            return FormatLine(lpTimeStr, cchTime, g_settings.topLine) + 1;
        }
    }

    int ret = GetTimeFormatEx_Original(lpLocaleName, dwFlags, lpTime, lpFormat,
                                       lpTimeStr, cchTime);

    return ret;
}

int WINAPI GetDateFormatEx_Hook_Win11(LPCWSTR lpLocaleName,
                                      DWORD dwFlags,
                                      CONST SYSTEMTIME* lpDate,
                                      LPCWSTR lpFormat,
                                      LPWSTR lpDateStr,
                                      int cchDate,
                                      LPCWSTR lpCalendar) {
    if (g_refreshIconThreadId == GetCurrentThreadId() &&
        !g_inGetTimeToolTipString) {
        // Below is a fix for the following situation. The code inside
        // winrt::SystemTray::implementation::ClockSystemTrayIconDataModel::RefreshIcon
        // looks similar to the following (pseudo code):
        //
        // ----------------------------------------
        // if (someFlag) {
        //     SYSTEMTIME t1;
        //     GetLocalTime(&t1);
        //     setTimeout(nextUpdate, calcNextUpdate(t1.wSecond));
        // }
        // SYSTEMTIME t2;
        // GetLocalTime(&t2);
        // GetDateFormatEx(..., &t2, ...);
        // ----------------------------------------
        //
        // We hook GetLocalTime and change wSecond to update the clock every
        // second, which works if someFlag is set. But in case someFlag isn't
        // set, we end up changing the result of the second GetLocalTime call.
        // To handle this, we check whether the time we get here is the time we
        // set in the hook, and if so, we call GetLocalTime explicitly to pass
        // the correct date to GetDateFormatEx.
        //
        // I'm not sure what someFlag means, but it becomes false when the
        // monitor turns off.

        SYSTEMTIME sentinelSystemTime;
        memset(&sentinelSystemTime, 0, sizeof(sentinelSystemTime));
        sentinelSystemTime.wSecond = 59;
        if (memcmp(lpDate, &sentinelSystemTime, sizeof(sentinelSystemTime)) ==
            0) {
            GetLocalTime_Original(const_cast<SYSTEMTIME*>(lpDate));
        }

        if (dwFlags & DATE_SHORTDATE) {
            if (!cchDate || g_winVersion >= WinVersion::Win11_22H2) {
                // First call, initialize strings.
                InitializeFormattedStrings(lpDate);
            }

            if (wcscmp(g_settings.bottomLine, L"-") != 0) {
                if (!cchDate) {
                    // Hopefully a large enough buffer size.
                    return FORMATTED_BUFFER_SIZE;
                }

                return FormatLine(lpDateStr, cchDate, g_settings.bottomLine) +
                       1;
            }
        }
    }

    int ret = GetDateFormatEx_Original(lpLocaleName, dwFlags, lpDate, lpFormat,
                                       lpDateStr, cchDate, lpCalendar);

    return ret;
}

#pragma endregion Win11Hooks

#pragma region Win10Hooks

DWORD g_updateTextStringThreadId;
int g_getDateFormatExCounter;
DWORD g_getTooltipTextThreadId;
WCHAR* g_getTooltipTextBuffer;
int g_getTooltipTextBufferSize;

using ClockButton_UpdateTextStringsIfNecessary_t =
    unsigned int(WINAPI*)(LPVOID pThis, bool*);
ClockButton_UpdateTextStringsIfNecessary_t
    ClockButton_UpdateTextStringsIfNecessary_Original;

using ClockButton_CalculateMinimumSize_t = LPSIZE(WINAPI*)(LPVOID pThis,
                                                           LPSIZE,
                                                           SIZE);
ClockButton_CalculateMinimumSize_t ClockButton_CalculateMinimumSize_Original;

using ClockButton_GetTextSpacingForOrientation_t =
    int(WINAPI*)(LPVOID pThis, bool, DWORD, DWORD, DWORD, DWORD);
ClockButton_GetTextSpacingForOrientation_t
    ClockButton_GetTextSpacingForOrientation_Original;

using ClockButton_v_GetTooltipText_t =
    HRESULT(WINAPI*)(LPVOID pThis, LPVOID, LPVOID, LPVOID, LPVOID);
ClockButton_v_GetTooltipText_t ClockButton_v_GetTooltipText_Original;

using ClockButton_v_OnDisplayStateChange_t = void(WINAPI*)(LPVOID pThis, bool);
ClockButton_v_OnDisplayStateChange_t
    ClockButton_v_OnDisplayStateChange_Original;

HRESULT WINAPI ClockButton_v_GetTooltipText_Hook(LPVOID pThis,
                                                 LPVOID param1,
                                                 LPVOID param2,
                                                 LPVOID param3,
                                                 LPVOID param4) {
    Wh_Log(L">");

    g_getTooltipTextThreadId = GetCurrentThreadId();

    HRESULT ret = ClockButton_v_GetTooltipText_Original(pThis, param1, param2,
                                                        param3, param4);

    if (g_getTooltipTextBuffer) {
        size_t stringLen = wcslen(g_getTooltipTextBuffer);
        WCHAR* p = g_getTooltipTextBuffer + stringLen;
        size_t size = g_getTooltipTextBufferSize + stringLen;
        if (size > 4) {
            wcscpy(p, L"\r\n\r\n");
            FormatLine(p + 4, size - 4, g_settings.tooltipLine);
        }
    }

    g_getTooltipTextBuffer = nullptr;
    g_getTooltipTextBufferSize = 0;

    g_getTooltipTextThreadId = 0;

    return ret;
}

unsigned int WINAPI
ClockButton_UpdateTextStringsIfNecessary_Hook(LPVOID pThis, bool* param1) {
    Wh_Log(L">");

    g_updateTextStringThreadId = GetCurrentThreadId();
    g_getDateFormatExCounter = 0;

    unsigned int ret =
        ClockButton_UpdateTextStringsIfNecessary_Original(pThis, param1);

    g_updateTextStringThreadId = 0;

    if (g_settings.showSeconds || !*g_webContent) {
        // Return the time-out value for the time of the next update.
        SYSTEMTIME time;
        GetLocalTime(&time);
        return 1000 - time.wMilliseconds;
    }

    return ret;
}

LPSIZE WINAPI ClockButton_CalculateMinimumSize_Hook(LPVOID pThis,
                                                    LPSIZE param1,
                                                    SIZE param2) {
    Wh_Log(L">");

    LPSIZE ret =
        ClockButton_CalculateMinimumSize_Original(pThis, param1, param2);

    HWND hWnd = *((HWND*)pThis + 1);
    UINT windowDpi = pGetDpiForWindow ? pGetDpiForWindow(hWnd) : 0;

    if (g_settings.width > 0) {
        ret->cx = g_settings.width;
        if (windowDpi) {
            ret->cx = MulDiv(ret->cx, windowDpi, 96);
        }
    }

    if (g_settings.height > 0) {
        ret->cy = g_settings.height;
        if (windowDpi) {
            ret->cy = MulDiv(ret->cy, windowDpi, 96);
        }
    }

    return ret;
}

int WINAPI ClockButton_GetTextSpacingForOrientation_Hook(LPVOID pThis,
                                                         bool horizontal,
                                                         DWORD dwSiteHeight,
                                                         DWORD dwLine1Height,
                                                         DWORD dwLine2Height,
                                                         DWORD dwLine3Height) {
    Wh_Log(L">");

    int textSpacing = g_settings.textSpacing;
    if (textSpacing == 0) {
        return ClockButton_GetTextSpacingForOrientation_Original(
            pThis, horizontal, dwSiteHeight, dwLine1Height, dwLine2Height,
            dwLine3Height);
    }

    // 1 line.
    if (dwLine3Height == 0 && dwLine2Height == 0) {
        return 0;
    }

    // Since 0 is reserved, shift negative values so that any spacing value can
    // be used.
    if (textSpacing < 0) {
        textSpacing++;
    }

    HWND hWnd = *((HWND*)pThis + 1);
    UINT windowDpi = pGetDpiForWindow ? pGetDpiForWindow(hWnd) : 0;

    if (windowDpi) {
        return MulDiv(textSpacing, windowDpi, 96);
    }

    return textSpacing;
}

int WINAPI GetTimeFormatEx_Hook_Win10(LPCWSTR lpLocaleName,
                                      DWORD dwFlags,
                                      CONST SYSTEMTIME* lpTime,
                                      LPCWSTR lpFormat,
                                      LPWSTR lpTimeStr,
                                      int cchTime) {
    if (g_updateTextStringThreadId == GetCurrentThreadId()) {
        InitializeFormattedStrings(lpTime);

        if (wcscmp(g_settings.topLine, L"-") != 0) {
            return FormatLine(lpTimeStr, cchTime, g_settings.topLine) + 1;
        }
    }

    int ret = GetTimeFormatEx_Original(lpLocaleName, dwFlags, lpTime, lpFormat,
                                       lpTimeStr, cchTime);

    return ret;
}

int WINAPI GetDateFormatEx_Hook_Win10(LPCWSTR lpLocaleName,
                                      DWORD dwFlags,
                                      CONST SYSTEMTIME* lpDate,
                                      LPCWSTR lpFormat,
                                      LPWSTR lpDateStr,
                                      int cchDate,
                                      LPCWSTR lpCalendar) {
    if (g_updateTextStringThreadId == GetCurrentThreadId()) {
        g_getDateFormatExCounter++;
        PCWSTR format = g_getDateFormatExCounter > 1 ? g_settings.middleLine
                                                     : g_settings.bottomLine;
        if (wcscmp(format, L"-") != 0) {
            return FormatLine(lpDateStr, cchDate, format) + 1;
        }
    }

    int ret = GetDateFormatEx_Original(lpLocaleName, dwFlags, lpDate, lpFormat,
                                       lpDateStr, cchDate, lpCalendar);

    return ret;
}

int WINAPI GetDateFormatW_Hook_Win10(LCID Locale,
                                     DWORD dwFlags,
                                     CONST SYSTEMTIME* lpDate,
                                     LPCWSTR lpFormat,
                                     LPWSTR lpDateStr,
                                     int cchDate) {
    if (g_getTooltipTextThreadId == GetCurrentThreadId() &&
        !g_getTooltipTextBuffer) {
        g_getTooltipTextBuffer = lpDateStr;
        g_getTooltipTextBufferSize = cchDate;
    }

    int ret = GetDateFormatW_Original(Locale, dwFlags, lpDate, lpFormat,
                                      lpDateStr, cchDate);

    return ret;
}

#pragma endregion Win10Hooks

VS_FIXEDFILEINFO* GetModuleVersionInfo(HMODULE hModule, UINT* puPtrLen) {
    void* pFixedFileInfo = nullptr;
    UINT uPtrLen = 0;

    HRSRC hResource =
        FindResource(hModule, MAKEINTRESOURCE(VS_VERSION_INFO), RT_VERSION);
    if (hResource) {
        HGLOBAL hGlobal = LoadResource(hModule, hResource);
        if (hGlobal) {
            void* pData = LockResource(hGlobal);
            if (pData) {
                if (!VerQueryValue(pData, L"\\", &pFixedFileInfo, &uPtrLen) ||
                    uPtrLen == 0) {
                    pFixedFileInfo = nullptr;
                    uPtrLen = 0;
                }
            }
        }
    }

    if (puPtrLen)
        *puPtrLen = uPtrLen;

    return (VS_FIXEDFILEINFO*)pFixedFileInfo;
}

WinVersion GetWindowsVersion() {
    VS_FIXEDFILEINFO* fixedFileInfo = GetModuleVersionInfo(nullptr, nullptr);
    if (!fixedFileInfo)
        return WinVersion::Unsupported;

    WORD major = HIWORD(fixedFileInfo->dwFileVersionMS);
    WORD minor = LOWORD(fixedFileInfo->dwFileVersionMS);
    WORD build = HIWORD(fixedFileInfo->dwFileVersionLS);
    WORD qfe = LOWORD(fixedFileInfo->dwFileVersionLS);

    Wh_Log(L"Version: %u.%u.%u.%u", major, minor, build, qfe);

    switch (major) {
        case 10:
            if (build < 22000)
                return WinVersion::Win10;
            else if (build <= 22000)
                return WinVersion::Win11;
            else
                return WinVersion::Win11_22H2;
            break;
    }

    return WinVersion::Unsupported;
}

struct SYMBOL_HOOK {
    std::vector<std::wstring_view> symbols;
    void** pOriginalFunction;
    void* hookFunction = nullptr;
    bool optional = false;
};

bool HookSymbols(HMODULE module,
                 const SYMBOL_HOOK* symbolHooks,
                 size_t symbolHooksCount) {
    const WCHAR cacheVer = L'1';
    const WCHAR cacheSep = L'@';
    constexpr size_t cacheMaxSize = 10240;

    WCHAR moduleFilePath[MAX_PATH];
    if (!GetModuleFileName(module, moduleFilePath, ARRAYSIZE(moduleFilePath))) {
        Wh_Log(L"GetModuleFileName failed");
        return false;
    }

    PCWSTR moduleFileName = wcsrchr(moduleFilePath, L'\\');
    if (!moduleFileName) {
        Wh_Log(L"GetModuleFileName returned unsupported path");
        return false;
    }

    moduleFileName++;

    WCHAR cacheBuffer[cacheMaxSize + 1];
    std::wstring cacheStrKey = std::wstring(L"symbol-cache-") + moduleFileName;
    Wh_GetStringValue(cacheStrKey.c_str(), cacheBuffer, ARRAYSIZE(cacheBuffer));

    std::wstring_view cacheBufferView(cacheBuffer);

    // https://stackoverflow.com/a/46931770
    auto splitStringView = [](std::wstring_view s, WCHAR delimiter) {
        size_t pos_start = 0, pos_end;
        std::wstring_view token;
        std::vector<std::wstring_view> res;

        while ((pos_end = s.find(delimiter, pos_start)) !=
               std::wstring_view::npos) {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + 1;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;
    };

    auto cacheParts = splitStringView(cacheBufferView, cacheSep);

    std::vector<bool> symbolResolved(symbolHooksCount, false);
    std::wstring newSystemCacheStr;

    auto onSymbolResolved = [symbolHooks, symbolHooksCount, &symbolResolved,
                             &newSystemCacheStr,
                             module](std::wstring_view symbol, void* address) {
        for (size_t i = 0; i < symbolHooksCount; i++) {
            if (symbolResolved[i]) {
                continue;
            }

            bool match = false;
            for (auto hookSymbol : symbolHooks[i].symbols) {
                if (hookSymbol == symbol) {
                    match = true;
                    break;
                }
            }

            if (!match) {
                continue;
            }

            if (symbolHooks[i].hookFunction) {
                Wh_SetFunctionHook(address, symbolHooks[i].hookFunction,
                                   symbolHooks[i].pOriginalFunction);
                Wh_Log(L"Hooked %p: %.*s", address, symbol.length(),
                       symbol.data());
            } else {
                *symbolHooks[i].pOriginalFunction = address;
                Wh_Log(L"Found %p: %.*s", address, symbol.length(),
                       symbol.data());
            }

            symbolResolved[i] = true;

            newSystemCacheStr += cacheSep;
            newSystemCacheStr += symbol;
            newSystemCacheStr += cacheSep;
            newSystemCacheStr +=
                std::to_wstring((ULONG_PTR)address - (ULONG_PTR)module);

            break;
        }
    };

    IMAGE_DOS_HEADER* dosHeader = (IMAGE_DOS_HEADER*)module;
    IMAGE_NT_HEADERS* header =
        (IMAGE_NT_HEADERS*)((BYTE*)dosHeader + dosHeader->e_lfanew);
    auto timeStamp = std::to_wstring(header->FileHeader.TimeDateStamp);
    auto imageSize = std::to_wstring(header->OptionalHeader.SizeOfImage);

    newSystemCacheStr += cacheVer;
    newSystemCacheStr += cacheSep;
    newSystemCacheStr += timeStamp;
    newSystemCacheStr += cacheSep;
    newSystemCacheStr += imageSize;

    if (cacheParts.size() >= 3 &&
        cacheParts[0] == std::wstring_view(&cacheVer, 1) &&
        cacheParts[1] == timeStamp && cacheParts[2] == imageSize) {
        for (size_t i = 3; i + 1 < cacheParts.size(); i += 2) {
            auto symbol = cacheParts[i];
            auto address = cacheParts[i + 1];
            if (address.length() == 0) {
                continue;
            }

            void* addressPtr =
                (void*)(std::stoull(std::wstring(address), nullptr, 10) +
                        (ULONG_PTR)module);

            onSymbolResolved(symbol, addressPtr);
        }

        for (size_t i = 0; i < symbolHooksCount; i++) {
            if (symbolResolved[i] || !symbolHooks[i].optional) {
                continue;
            }

            size_t noAddressMatchCount = 0;
            for (size_t j = 3; j + 1 < cacheParts.size(); j += 2) {
                auto symbol = cacheParts[j];
                auto address = cacheParts[j + 1];
                if (address.length() != 0) {
                    continue;
                }

                for (auto hookSymbol : symbolHooks[i].symbols) {
                    if (hookSymbol == symbol) {
                        noAddressMatchCount++;
                        break;
                    }
                }
            }

            if (noAddressMatchCount == symbolHooks[i].symbols.size()) {
                Wh_Log(L"Optional symbol %d doesn't exist (from cache)", i);
                symbolResolved[i] = true;
            }
        }

        if (std::all_of(symbolResolved.begin(), symbolResolved.end(),
                        [](bool b) { return b; })) {
            return true;
        }
    }

    Wh_Log(L"Couldn't resolve all symbols from cache");

    WH_FIND_SYMBOL findSymbol;
    HANDLE findSymbolHandle = Wh_FindFirstSymbol(module, nullptr, &findSymbol);
    if (!findSymbolHandle) {
        Wh_Log(L"Wh_FindFirstSymbol failed");
        return false;
    }

    do {
        onSymbolResolved(findSymbol.symbol, findSymbol.address);
    } while (Wh_FindNextSymbol(findSymbolHandle, &findSymbol));

    Wh_FindCloseSymbol(findSymbolHandle);

    for (size_t i = 0; i < symbolHooksCount; i++) {
        if (symbolResolved[i]) {
            continue;
        }

        if (!symbolHooks[i].optional) {
            Wh_Log(L"Unresolved symbol: %d", i);
            return false;
        }

        Wh_Log(L"Optional symbol %d doesn't exist", i);

        for (auto hookSymbol : symbolHooks[i].symbols) {
            newSystemCacheStr += cacheSep;
            newSystemCacheStr += hookSymbol;
            newSystemCacheStr += cacheSep;
        }
    }

    if (newSystemCacheStr.length() <= cacheMaxSize) {
        Wh_SetStringValue(cacheStrKey.c_str(), newSystemCacheStr.c_str());
    } else {
        Wh_Log(L"Cache is too large (%zu)", newSystemCacheStr.length());
    }

    return true;
}

void LoadSettings() {
    g_settings.showSeconds = Wh_GetIntSetting(L"ShowSeconds");
    g_settings.timeFormat = Wh_GetStringSetting(L"TimeFormat");
    g_settings.dateFormat = Wh_GetStringSetting(L"DateFormat");
    g_settings.weekdayFormat = Wh_GetStringSetting(L"WeekdayFormat");
    g_settings.topLine = Wh_GetStringSetting(L"TopLine");
    g_settings.bottomLine = Wh_GetStringSetting(L"BottomLine");
    g_settings.middleLine = Wh_GetStringSetting(L"MiddleLine");
    g_settings.tooltipLine = Wh_GetStringSetting(L"TooltipLine");
    g_settings.width = Wh_GetIntSetting(L"Width");
    g_settings.height = Wh_GetIntSetting(L"Height");
    g_settings.textSpacing = Wh_GetIntSetting(L"TextSpacing");
    g_settings.webContentsUrl = Wh_GetStringSetting(L"WebContentsUrl");
    g_settings.webContentsBlockStart =
        Wh_GetStringSetting(L"WebContentsBlockStart");
    g_settings.webContentsStart = Wh_GetStringSetting(L"WebContentsStart");
    g_settings.webContentsEnd = Wh_GetStringSetting(L"WebContentsEnd");
    g_settings.webContentsMaxLength = Wh_GetIntSetting(L"WebContentsMaxLength");
    g_settings.webContentsUpdateInterval =
        Wh_GetIntSetting(L"WebContentsUpdateInterval");

    g_settings.timeStyle.visible = Wh_GetIntSetting(L"TimeStyle.Visible");
    g_settings.timeStyle.textColor =
        Wh_GetStringSetting(L"TimeStyle.TextColor");
    g_settings.timeStyle.fontSize = Wh_GetIntSetting(L"TimeStyle.FontSize");
    g_settings.timeStyle.fontFamily =
        Wh_GetStringSetting(L"TimeStyle.FontFamily");
    g_settings.timeStyle.fontWeight =
        Wh_GetStringSetting(L"TimeStyle.FontWeight");
    g_settings.timeStyle.fontStyle =
        Wh_GetStringSetting(L"TimeStyle.FontStyle");
    g_settings.timeStyle.fontStretch =
        Wh_GetStringSetting(L"TimeStyle.FontStretch");
    g_settings.timeStyle.characterSpacing =
        Wh_GetIntSetting(L"TimeStyle.CharacterSpacing");

    g_settings.dateStyle.textColor =
        Wh_GetStringSetting(L"DateStyle.TextColor");
    g_settings.dateStyle.fontSize = Wh_GetIntSetting(L"DateStyle.FontSize");
    g_settings.dateStyle.fontFamily =
        Wh_GetStringSetting(L"DateStyle.FontFamily");
    g_settings.dateStyle.fontWeight =
        Wh_GetStringSetting(L"DateStyle.FontWeight");
    g_settings.dateStyle.fontStyle =
        Wh_GetStringSetting(L"DateStyle.FontStyle");
    g_settings.dateStyle.fontStretch =
        Wh_GetStringSetting(L"DateStyle.FontStretch");
    g_settings.dateStyle.characterSpacing =
        Wh_GetIntSetting(L"DateStyle.CharacterSpacing");

    g_settings.oldTaskbarOnWin11 = Wh_GetIntSetting(L"oldTaskbarOnWin11");
}

void ApplySettingsWin11() {
    DWORD dwProcessId;
    DWORD dwCurrentProcessId = GetCurrentProcessId();

    HWND hTaskbarWnd = FindWindow(L"Shell_TrayWnd", nullptr);
    if (hTaskbarWnd && GetWindowThreadProcessId(hTaskbarWnd, &dwProcessId) &&
        dwProcessId == dwCurrentProcessId) {
        // Trigger a time change notification. Do so only if the current
        // explorer.exe instance owns the taskbar.
        WCHAR szTimeFormat[80];
        if (GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_STIMEFORMAT, szTimeFormat,
                          ARRAYSIZE(szTimeFormat))) {
            SetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_STIMEFORMAT,
                          szTimeFormat);
        }
    }
}

void ApplySettingsWin10() {
    DWORD dwProcessId;
    DWORD dwCurrentProcessId = GetCurrentProcessId();

    HWND hTaskbarWnd = FindWindow(L"Shell_TrayWnd", nullptr);
    if (hTaskbarWnd && GetWindowThreadProcessId(hTaskbarWnd, &dwProcessId) &&
        dwProcessId == dwCurrentProcessId) {
        // Apply size.
        RECT rc;
        if (GetClientRect(hTaskbarWnd, &rc)) {
            SendMessage(hTaskbarWnd, WM_SIZE, SIZE_RESTORED,
                        MAKELPARAM(rc.right - rc.left, rc.bottom - rc.top));
        }

        // Apply text.
        HWND hTrayNotifyWnd =
            FindWindowEx(hTaskbarWnd, nullptr, L"TrayNotifyWnd", nullptr);
        if (hTrayNotifyWnd) {
            HWND hTrayClockWWnd = FindWindowEx(hTrayNotifyWnd, nullptr,
                                               L"TrayClockWClass", nullptr);
            if (hTrayClockWWnd) {
                LONG_PTR lpTrayClockWClassLongPtr =
                    GetWindowLongPtr(hTrayClockWWnd, 0);
                if (lpTrayClockWClassLongPtr) {
                    ClockButton_v_OnDisplayStateChange_Original(
                        (LPVOID)lpTrayClockWClassLongPtr, true);
                }
            }
        }
    }

    HWND hSecondaryTaskbarWnd = FindWindow(L"Shell_SecondaryTrayWnd", nullptr);
    while (hSecondaryTaskbarWnd &&
           GetWindowThreadProcessId(hSecondaryTaskbarWnd, &dwProcessId) &&
           dwProcessId == dwCurrentProcessId) {
        // Apply size.
        RECT rc;
        if (GetClientRect(hSecondaryTaskbarWnd, &rc)) {
            WINDOWPOS windowpos;
            windowpos.hwnd = hSecondaryTaskbarWnd;
            windowpos.hwndInsertAfter = nullptr;
            windowpos.x = 0;
            windowpos.y = 0;
            windowpos.cx = rc.right - rc.left;
            windowpos.cy = rc.bottom - rc.top;
            windowpos.flags = SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE;

            SendMessage(hSecondaryTaskbarWnd, WM_WINDOWPOSCHANGED, 0,
                        (LPARAM)&windowpos);
        }

        // Apply text.
        HWND hClockButtonWnd = FindWindowEx(hSecondaryTaskbarWnd, nullptr,
                                            L"ClockButton", nullptr);
        if (hClockButtonWnd) {
            LONG_PTR lpClockButtonLongPtr =
                GetWindowLongPtr(hClockButtonWnd, 0);
            if (lpClockButtonLongPtr) {
                ClockButton_v_OnDisplayStateChange_Original(
                    (LPVOID)lpClockButtonLongPtr, true);
            }
        }

        hSecondaryTaskbarWnd = FindWindowEx(nullptr, hSecondaryTaskbarWnd,
                                            L"Shell_SecondaryTrayWnd", nullptr);
    }
}

void ApplySettings() {
    if (g_winVersion >= WinVersion::Win11) {
        ApplySettingsWin11();
    } else {
        ApplySettingsWin10();
    }
}

BOOL Wh_ModInit() {
    Wh_Log(L">");

    LoadSettings();

    g_winVersion = GetWindowsVersion();
    if (g_winVersion == WinVersion::Unsupported) {
        Wh_Log(L"Unsupported Windows version");
        return FALSE;
    }

    if (g_winVersion >= WinVersion::Win11 && g_settings.oldTaskbarOnWin11) {
        g_winVersion = WinVersion::Win10;
    }

    HMODULE hUser32 = LoadLibrary(L"user32.dll");
    if (hUser32) {
        pGetDpiForWindow =
            (GetDpiForWindow_t)GetProcAddress(hUser32, "GetDpiForWindow");
    }

    SYMBOL_HOOK taskbarHooks11[] = {
        {
            {
                LR"(private: void __cdecl winrt::SystemTray::implementation::ClockSystemTrayIconDataModel::RefreshIcon(class SystemTrayTelemetry::ClockUpdate &))",
                LR"(private: void __cdecl winrt::SystemTray::implementation::ClockSystemTrayIconDataModel::RefreshIcon(class SystemTrayTelemetry::ClockUpdate & __ptr64) __ptr64)",
            },
            (void**)&ClockSystemTrayIconDataModel_RefreshIcon_Original,
            (void*)ClockSystemTrayIconDataModel_RefreshIcon_Hook,
        },
        {
            {
                LR"(private: struct winrt::hstring __cdecl winrt::SystemTray::implementation::ClockSystemTrayIconDataModel::GetTimeToolTipString(struct _SYSTEMTIME const &,struct _SYSTEMTIME const &,class SystemTrayTelemetry::ClockUpdate &))",
                LR"(private: struct winrt::hstring __cdecl winrt::SystemTray::implementation::ClockSystemTrayIconDataModel::GetTimeToolTipString(struct _SYSTEMTIME const & __ptr64,struct _SYSTEMTIME const & __ptr64,class SystemTrayTelemetry::ClockUpdate & __ptr64) __ptr64)",
            },
            (void**)&ClockSystemTrayIconDataModel_GetTimeToolTipString_Original,
            (void*)ClockSystemTrayIconDataModel_GetTimeToolTipString_Hook,
            true,
        },
        {
            {
                LR"(public: void __cdecl winrt::SystemTray::implementation::DateTimeIconContent::OnApplyTemplate(void))",
                LR"(public: void __cdecl winrt::SystemTray::implementation::DateTimeIconContent::OnApplyTemplate(void) __ptr64)",
            },
            (void**)&DateTimeIconContent_OnApplyTemplate_Original,
            (void*)DateTimeIconContent_OnApplyTemplate_Hook,
            true,
        },
        {
            {
                LR"(public: __cdecl winrt::Windows::UI::Xaml::Controls::IControlOverridesT<struct winrt::SystemTray::implementation::DateTimeIconContent>::OnPointerEntered(struct winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const &)const )",
                LR"(public: __cdecl winrt::Windows::UI::Xaml::Controls::IControlOverridesT<struct winrt::SystemTray::implementation::DateTimeIconContent>::OnPointerEntered(struct winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const & __ptr64)const __ptr64)",
            },
            (void**)&DateTimeIconContent_OnPointerEntered_Original,
            (void*)DateTimeIconContent_OnPointerEntered_Hook,
            true,
        },
        {
            {
                LR"(const winrt::SystemTray::implementation::DateTimeIconContent::`vftable')",
                LR"(const winrt::SystemTray::implementation::DateTimeIconContent::`vftable' __ptr64)",
            },
            &DateTimeIconContent_vftable,
            nullptr,
            true,
        },
        {
            {
                LR"(private: struct winrt::hstring __cdecl winrt::SystemTray::implementation::ClockSystemTrayIconDataModel::GetTimeToolTipString(struct _SYSTEMTIME *,struct _TIME_DYNAMIC_ZONE_INFORMATION *,class SystemTrayTelemetry::ClockUpdate &))",
                LR"(private: struct winrt::hstring __cdecl winrt::SystemTray::implementation::ClockSystemTrayIconDataModel::GetTimeToolTipString(struct _SYSTEMTIME * __ptr64,struct _TIME_DYNAMIC_ZONE_INFORMATION * __ptr64,class SystemTrayTelemetry::ClockUpdate & __ptr64) __ptr64)",
            },
            (void**)&ClockSystemTrayIconDataModel_GetTimeToolTipString_2_Original,
            (void*)ClockSystemTrayIconDataModel_GetTimeToolTipString_2_Hook,
            true,  // Until Windows 11 version 21H2.
        },
        {
            {
                LR"(public: int __cdecl winrt::impl::consume_Windows_Globalization_ICalendar<struct winrt::Windows::Globalization::ICalendar>::Second(void)const )",
                LR"(public: int __cdecl winrt::impl::consume_Windows_Globalization_ICalendar<struct winrt::Windows::Globalization::ICalendar>::Second(void)const __ptr64)",
            },
            (void**)&ICalendar_Second_Original,
            (void*)ICalendar_Second_Hook,
            true,  // Until Windows 11 version 21H2.
        },
    };

    SYMBOL_HOOK taskbarHooks10[] = {
        {
            {
                LR"(private: unsigned int __cdecl ClockButton::UpdateTextStringsIfNecessary(bool *))",
                LR"(private: unsigned int __cdecl ClockButton::UpdateTextStringsIfNecessary(bool * __ptr64) __ptr64)",
            },
            (void**)&ClockButton_UpdateTextStringsIfNecessary_Original,
            (void*)ClockButton_UpdateTextStringsIfNecessary_Hook,
        },
        {
            {
                LR"(public: struct tagSIZE __cdecl ClockButton::CalculateMinimumSize(struct tagSIZE))",
                LR"(public: struct tagSIZE __cdecl ClockButton::CalculateMinimumSize(struct tagSIZE) __ptr64)",
            },
            (void**)&ClockButton_CalculateMinimumSize_Original,
            (void*)ClockButton_CalculateMinimumSize_Hook,
        },
        {
            {
                LR"(private: int __cdecl ClockButton::GetTextSpacingForOrientation(bool,int,int,int,int))",
                LR"(private: int __cdecl ClockButton::GetTextSpacingForOrientation(bool,int,int,int,int) __ptr64)",
            },
            (void**)&ClockButton_GetTextSpacingForOrientation_Original,
            (void*)ClockButton_GetTextSpacingForOrientation_Hook,
        },
        {
            {
                LR"(protected: virtual long __cdecl ClockButton::v_GetTooltipText(struct HINSTANCE__ * *,unsigned short * *,unsigned short *,unsigned __int64))",
                LR"(protected: virtual long __cdecl ClockButton::v_GetTooltipText(struct HINSTANCE__ * __ptr64 * __ptr64,unsigned short * __ptr64 * __ptr64,unsigned short * __ptr64,unsigned __int64) __ptr64)",
            },
            (void**)&ClockButton_v_GetTooltipText_Original,
            (void*)ClockButton_v_GetTooltipText_Hook,
            true,
        },
        {
            {
                LR"(protected: virtual void __cdecl ClockButton::v_OnDisplayStateChange(bool))",
                LR"(protected: virtual void __cdecl ClockButton::v_OnDisplayStateChange(bool) __ptr64)",
            },
            (void**)&ClockButton_v_OnDisplayStateChange_Original,
        },
    };

    if (g_winVersion <= WinVersion::Win10) {
        if (!HookSymbols(GetModuleHandle(nullptr), taskbarHooks10,
                         ARRAYSIZE(taskbarHooks10))) {
            return FALSE;
        }
    } else {
        WCHAR szWindowsDirectory[MAX_PATH];
        if (!GetWindowsDirectory(szWindowsDirectory,
                                 ARRAYSIZE(szWindowsDirectory))) {
            Wh_Log(L"GetWindowsDirectory failed");
            return FALSE;
        }

        HMODULE module = nullptr;

        if (g_winVersion == WinVersion::Win11) {
            WCHAR szTargetDllPath[MAX_PATH];
            wcscpy_s(szTargetDllPath, szWindowsDirectory);
            wcscat_s(
                szTargetDllPath,
                LR"(\SystemApps\MicrosoftWindows.Client.CBS_cw5n1h2txyewy\ExplorerExtensions.dll)");

            module = GetModuleHandle(szTargetDllPath);
            if (!module) {
                // Try to load dependency DLLs. At process start, if they're not
                // loaded, loading the ExplorerExtensions DLL fails.
                WCHAR szRuntimeDllPath[MAX_PATH];

                PWSTR pProgramFilesDirectory;
                if (FAILED(SHGetKnownFolderPath(FOLDERID_ProgramFiles, 0,
                                                nullptr,
                                                &pProgramFilesDirectory))) {
                    Wh_Log(
                        L"SHGetKnownFolderPath(FOLDERID_ProgramFiles) failed");
                    return FALSE;
                }

                wcscpy_s(szRuntimeDllPath, pProgramFilesDirectory);
                wcscat_s(
                    szRuntimeDllPath,
                    LR"(\WindowsApps\Microsoft.VCLibs.140.00_14.0.29231.0_x64__8wekyb3d8bbwe\vcruntime140_app.dll)");
                LoadLibrary(szRuntimeDllPath);

                wcscpy_s(szRuntimeDllPath, pProgramFilesDirectory);
                wcscat_s(
                    szRuntimeDllPath,
                    LR"(\WindowsApps\Microsoft.VCLibs.140.00_14.0.29231.0_x64__8wekyb3d8bbwe\vcruntime140_1_app.dll)");
                LoadLibrary(szRuntimeDllPath);

                wcscpy_s(szRuntimeDllPath, pProgramFilesDirectory);
                wcscat_s(
                    szRuntimeDllPath,
                    LR"(\WindowsApps\Microsoft.VCLibs.140.00_14.0.29231.0_x64__8wekyb3d8bbwe\msvcp140_app.dll)");
                LoadLibrary(szRuntimeDllPath);

                CoTaskMemFree(pProgramFilesDirectory);

                module = LoadLibraryEx(szTargetDllPath, nullptr,
                                       LOAD_WITH_ALTERED_SEARCH_PATH);
            }
        } else {
            WCHAR szTargetDllPath[MAX_PATH];
            wcscpy_s(szTargetDllPath, szWindowsDirectory);
            wcscat_s(
                szTargetDllPath,
                LR"(\SystemApps\MicrosoftWindows.Client.Core_cw5n1h2txyewy\Taskbar.View.dll)");

            module = LoadLibraryEx(szTargetDllPath, nullptr,
                                   LOAD_WITH_ALTERED_SEARCH_PATH);
        }

        if (!module) {
            Wh_Log(L"Failed loading Taskbar View module");
            return FALSE;
        }

        if (!HookSymbols(module, taskbarHooks11, ARRAYSIZE(taskbarHooks11))) {
            return FALSE;
        }
    }

    // Must use GetProcAddress for the functions below, otherwise the stubs in
    // kernel32.dll are being hooked.
    HMODULE hKernelBase = GetModuleHandle(L"kernelbase.dll");
    if (!hKernelBase) {
        return FALSE;
    }

    FARPROC pGetTimeFormatEx = GetProcAddress(hKernelBase, "GetTimeFormatEx");
    if (!pGetTimeFormatEx) {
        return FALSE;
    }

    FARPROC pGetDateFormatEx = GetProcAddress(hKernelBase, "GetDateFormatEx");
    if (!pGetDateFormatEx) {
        return FALSE;
    }

    if (g_winVersion <= WinVersion::Win10) {
        Wh_SetFunctionHook((void*)pGetTimeFormatEx,
                           (void*)GetTimeFormatEx_Hook_Win10,
                           (void**)&GetTimeFormatEx_Original);
        Wh_SetFunctionHook((void*)pGetDateFormatEx,
                           (void*)GetDateFormatEx_Hook_Win10,
                           (void**)&GetDateFormatEx_Original);

        FARPROC pGetDateFormatW = GetProcAddress(hKernelBase, "GetDateFormatW");
        if (pGetDateFormatW) {
            Wh_SetFunctionHook((void*)pGetDateFormatW,
                               (void*)GetDateFormatW_Hook_Win10,
                               (void**)&GetDateFormatW_Original);
        }
    } else {
        if (g_winVersion >= WinVersion::Win11_22H2) {
            FARPROC pGetLocalTime = GetProcAddress(hKernelBase, "GetLocalTime");
            if (!pGetLocalTime) {
                return FALSE;
            }

            Wh_SetFunctionHook((void*)pGetLocalTime,
                               (void*)GetLocalTime_Hook_Win11,
                               (void**)&GetLocalTime_Original);
        }

        Wh_SetFunctionHook((void*)pGetTimeFormatEx,
                           (void*)GetTimeFormatEx_Hook_Win11,
                           (void**)&GetTimeFormatEx_Original);
        Wh_SetFunctionHook((void*)pGetDateFormatEx,
                           (void*)GetDateFormatEx_Hook_Win11,
                           (void**)&GetDateFormatEx_Original);
    }

    return TRUE;
}

void Wh_ModAfterInit() {
    Wh_Log(L">");

    WebContentUpdateThreadInit();

    ApplySettings();
}

void Wh_ModUninit() {
    Wh_Log(L">");

    WebContentUpdateThreadUninit();

    ApplySettings();
}

BOOL Wh_ModSettingsChanged(BOOL* bReload) {
    Wh_Log(L">");

    WebContentUpdateThreadUninit();

    bool prevOldTaskbarOnWin11 = g_settings.oldTaskbarOnWin11;

    LoadSettings();

    *bReload = g_settings.oldTaskbarOnWin11 != prevOldTaskbarOnWin11;
    if (*bReload) {
        return TRUE;
    }

    WebContentUpdateThreadInit();

    ApplySettings();

    return TRUE;
}

// For pre-1.3 Windhawk compatibility.
void Wh_ModSettingsChanged() {
    Wh_Log(L"> pre-1.3");

    WebContentUpdateThreadUninit();

    LoadSettings();

    WebContentUpdateThreadInit();

    ApplySettings();
}
