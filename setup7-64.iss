; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "ChessX"
#define MyAppVersion "1.0.0"
#define MyAppPublisher "chessx.sourceforge.net"
#define MyAppURL "http://chessx.sourceforge.net"
#define MyAppExeName "chessx.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{278EF322-A05B-4F81-B23B-F7D8050F6837}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}\build-chessx-Desktop_Qt_5_1_0_MSVC2012_64bit-Release\release
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
AllowNoIcons=yes
LicenseFile=.\COPYING
OutputBaseFilename=setup-chessx7-64
SetupIconFile=.\src\chessx.ico
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; OnlyBelowVersion: 0,6.1

[Files]
Source: "..\build-chessx-Desktop_Qt_5_1_0_MSVC2012_64bit-Release\release\chessx.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\build-chessx-Desktop_Qt_5_1_0_MSVC2012_64bit-Release\release\*.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: ".\COPYING"; DestDir: "{app}"; Flags: ignoreversion
Source: ".\ChangeLog"; DestDir: "{app}"
Source: ".\data\engines\*.exe"; DestDir: "{app}\data\engines\"; Flags: ignoreversion recursesubdirs createallsubdirs

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

