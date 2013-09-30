//========== IV:Multiplayer - https://github.com/IVMultiplayer/IVMultiplayer ==========
//
// File: CGUI.cpp
// Project: Client.Core
// Author: ViruZz <blazee14@gmail.com>
// License: See LICENSE in root directory
//
//==============================================================================

#ifndef CGUI_h
#define CGUI_h

#include <Common.h>
#include <CEGUI.h>
#include <dinput.h>
#include <RendererModules/Direct3D9/CEGUIDirect3D9Renderer.h>

#define STYLE_SCHEME "WindowsLook.scheme"
#define STYLE_PREFIX "WindowsLook"
#define STYLE_IMAGES "WindowsLook"

#define InheritedStruct(inheritFrom, structName) struct structName : inheritFrom { }

struct CGUIWindow : CEGUI::Window
{
	std::string getText();
};

InheritedStruct(CGUIWindow, CGUIButton);
InheritedStruct(CGUIWindow, CGUIStaticImage);
InheritedStruct(CGUIWindow, CGUIProgressBar);

class CGUI 
{
public:
	CGUI(IDirect3DDevice9* pDevice);
	~CGUI();

	void Render();
	bool Initialize();

	const char	  * GetUniqueName();
	bool			OnGUIKeyDown(const CEGUI::EventArgs &eventArgs);

	unsigned int	GetDisplayWidth();
	unsigned int	GetDisplayHeight();

	void			OnLostDevice();
	void			OnResetDevice();

	void			SetCursorVisible(bool bVisible);

	CEGUI::Direct3D9Renderer * GetRenderer() { return m_pRenderer; }
	CEGUI::System            * GetSystem() { return m_pSystem; }
	CEGUI::WindowManager     * GetWindowManager() { return m_pWindowManager; }
	CEGUI::DefaultWindow     * GetDefaultWindow() { return m_pDefaultWindow; }
	CEGUI::Font              * GetFont(CString strFont, unsigned int uiSize = 8, bool bScaled = false);

	// Later on we'll need to make this a single function with seperate types
	void                       RemoveGUIWindow(CEGUI::String &sName);
	void                       RemoveGUIWindow(CEGUI::Window * pWindow);
	CEGUI::Window            * CreateGUIWindow(const CEGUI::String &sType, const CEGUI::String &sName = "", CEGUI::Window * pParentWindow = NULL);
	CGUIStaticImage          * CreateGUIStaticImage(CEGUI::String &sName, CEGUI::Window * pParentWindow = NULL);
	CGUIStaticImage          * CreateGUIStaticImage(CEGUI::Window * pParentWindow = NULL);
	CGUIButton               * CreateGUIButton(CEGUI::String &sName, CEGUI::Window * pParentWindow = NULL);
	CGUIButton               * CreateGUIButton(CEGUI::Window * pParentWindow = NULL);
	CGUIProgressBar			 * CreateGUIProgressBar(CEGUI::String &sName, CEGUI::Window * pParentWindow = NULL);
	CGUIProgressBar		     * CreateGUIProgressBar(CEGUI::Window * pParentWindow = NULL);

	void Test();
private:
	IDirect3DDevice9		 * m_pD3DDevice;
	// DX-based renderer
	CEGUI::Direct3D9Renderer * m_pRenderer;
	CEGUI::System            * m_pSystem;
	CEGUI::Scheme            * m_pScheme;
	CEGUI::MouseCursor       * m_pCursor;
	CEGUI::WindowManager     * m_pWindowManager;
	CEGUI::FontManager       * m_pFontManager;
	CEGUI::GeometryBuffer    * m_pTextDrawingGeometryBuffer;
	CEGUI::DefaultWindow     * m_pDefaultWindow;


	IDirectInput8            * m_pInput;
	IDirectInputDevice8      * m_pInputMouse;
	bool                       m_bInitialized;
	bool					   m_bScriptedCursorVisible;
	DWORD                      m_dwInputAxes;
	DWORD                      m_dwInputButtons;
	DIMOUSESTATE2              m_MouseState;
	DWORD                      dwLastClickTime[8];
	BYTE                       byteButtonWasClicked[8];
	BYTE                       byteButtonClicked[8];
	RECT                       m_rCursorPosition;
	int                        m_iCurrentId;
	DWORD                      m_dwDoubleClickTime;
	POINT                      m_clickPosition;
	unsigned int               m_uiCurrentJenkFag;

	int m_iScreenWidth;
	int m_iScreenHeight;
};

#endif