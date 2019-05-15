; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���

#define MyAppName "ScreenProduce"
#define MyAppVersion "1.0"
#define MyAppPublisher "lonbon"
#define MyAppURL "http://www.lonbon.com/"
#define MyAppExeName "ScreenProduceTool.exe"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{7D046E8A-C0BD-48D2-8539-FB2956BB2ED4}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
OutputBaseFilename=Screenproduce
Compression=lzma
SolidCompression=yes

[Languages]
Name: "chinesesimp"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "D:\projects\ScreenProduceTool\Debug\ScreenProduceTool.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\projects\ScreenProduceTool\Debug\mfc120ud.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\projects\ScreenProduceTool\Debug\msvcp120d.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\projects\ScreenProduceTool\Debug\msvcr120d.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\projects\ScreenProduceTool\Debug\mfc120u.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\projects\ScreenProduceTool\Debug\msvcp120.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\projects\ScreenProduceTool\Debug\msvcr120.dll"; DestDir: "{app}"; Flags: ignoreversion
; ע��: ��Ҫ���κι���ϵͳ�ļ���ʹ�á�Flags: ignoreversion��

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

