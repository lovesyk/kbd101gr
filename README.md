# kbd101gr
## Description
kbd101gr is a Windows keyboard layout file mapping the Japanese onto the German keyboard.

This layout has several advantages over the plain German kbdgr layout:

  * kana input is possible using the same layout as on US keyboards
  * IME shortcuts involving NLS keys are working
  * dead keys are disabled as they are not supported by Japanese input

This layout does not solve all remaining issues:

  * redirecting the layout file to this one is still a modification that can be overwritten by any update or Windows repair
  * dead keys are still not working and hence disabled at least
  * IME's letter capturing still breaks on e. g. the control + alt modifier
  
As an addition it is possible to enter ¥ using control + alt + y.

## Install
On 64-bit systems, copy the contents of the extracted archive into your Windows directory.

On 32-bit systems, copy the DLL from the SysWOW64 directory of the extracted archive into your System32 directory.

Redirect the Japanese kbdjpn layout to kbd101gr by browsing to the 
`HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Keyboard Layouts\00000411` registry key
and changing the `Layout File` value to `kbd101gr.dll`.

Log out and back in and the new layout will be applied.

## Warnings
  * As this is a modification of Windows, an update or repair process could revert the installation.
  * This layout is based on code of Windows 10, version 1607 and the releases were compiled with Visual Studio 2015 Update 3 using the WDK for Windows 10, version 1703. The releases were only tested on Windows 10, version 1703 and Windows Server 2016 and may not be compatible with all Windows versions.