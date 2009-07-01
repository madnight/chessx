; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!
; This is the Inno Setup script for ChessX.
; Inno Setup creates install files for MS Windows.

#define MyAppName "ChessX"
#define MyAppVerName "ChessX-0.6"
#define MyAppPublisher "ChessX Team"
#define MyAppURL "http://chessx.sourceforge.net"
#define MyAppExeName "chessx.exe"

[Setup]
AppName={#MyAppName}
AppVerName={#MyAppVerName}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
OutputBaseFilename={#MyAppVerName}
Compression=lzma/ultra
InternalCompressLevel=ultra
SolidCompression=true

[Languages]
Name: "eng"; MessagesFile: "compiler:Default.isl"
Name: brazilianportuguese; MessagesFile: compiler:Languages\BrazilianPortuguese.isl
Name: czech; MessagesFile: compiler:Languages\Czech.isl
Name: dutch; MessagesFile: compiler:Languages\Dutch.isl
Name: french; MessagesFile: compiler:Languages\French.isl
Name: german; MessagesFile: compiler:Languages\German.isl
Name: hungarian; MessagesFile: compiler:Languages\Hungarian.isl
Name: italian; MessagesFile: compiler:Languages\Italian.isl
Name: norwegian; MessagesFile: compiler:Languages\Norwegian.isl
Name: polish; MessagesFile: compiler:Languages\Polish.isl
Name: spanish; MessagesFile: compiler:Languages\Spanish.isl

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "bin\chessx.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "COPYING"; DestDir: "{app}"; Flags: ignoreversion
Source: "TODO"; DestDir: "{app}"; Flags: ignoreversion
Source: "Changelog"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\MinGW\bin\mingwm10.dll"; DestDir: "{sys}";
Source: "data\*.*"; DestDir: "{app}\data"; Flags: ignoreversion recursesubdirs
Source: "C:\Qt\4.5.0\bin\QtCore4.dll"; DestDir: "{sys}";
Source: "C:\Qt\4.5.0\bin\QtGui4.dll"; DestDir: "{sys}";
Source: "C:\Qt\4.5.0\bin\QtNetwork4.dll"; DestDir: "{sys}";
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; WorkingDir: "{app}"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{userdesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; WorkingDir: "{app}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; WorkingDir: "{app}"; Tasks: quicklaunchicon

[Run]
Filename: {app}\{#MyAppExeName}; Description: {cm:LaunchProgram,{#MyAppName}}; Flags: nowait postinstall skipifsilent
