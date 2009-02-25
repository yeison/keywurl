#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>
#import <Foundation/Foundation.h>

@protocol ProvidesSearchTarget
- (id)targetForSearch;
@end

@protocol ReopensAtLaunch
+ (void)reopen;
@end

@interface WindowController : NSWindowController
{
    NSString *_multiWindowFrameAutosaveName;
    BOOL _autosaveFrame;
    BOOL _lastResizeWasProgrammatic;
}

- (void)dealloc;
- (void)_saveFrameIfAllowed;
- (void)windowDidMove:(id)fp8;
- (void)windowDidResize:(id)fp8;
- (void)_windowWillClose:(id)fp8;
- (BOOL)setMultiWindowFrameAutosaveName:(id)fp8;
- (id)multiWindowFrameAutosaveName;
- (void)_setFrameWithoutAutosaving:(struct _NSRect)fp8 programmatically:(BOOL)fp24;
- (void)setFrameWithoutAutosaving:(struct _NSRect)fp8;
- (void)setFrameProgrammatically:(struct _NSRect)fp8;
- (struct _NSRect)defaultFrame;
- (void)setFrameToDefault;
- (void)_windowDidLoad;
- (void)setFrameAutosaveEnabled:(BOOL)fp8;
- (BOOL)frameAutosaveEnabled;

@end

@interface TextFieldEditor : NSTextView
{
}

- (id)init;
- (void)stripCarriageReturnsAfterPaste;
- (void)paste:(id)fp8;

@end

@interface LocationFieldEditor : TextFieldEditor
{
@public
    NSTextField *field;
}

- (id)initWithField:(id)fp8;
- (unsigned int)validModesForFontPanel:(id)fp8;
- (void)changeFont:(id)fp8;
- (id)acceptableDragTypes;
- (unsigned int)draggingEntered:(id)fp8;
- (unsigned int)draggingUpdated:(id)fp8;
- (BOOL)prepareForDragOperation:(id)fp8;
- (BOOL)performDragOperation:(id)fp8;
- (void)concludeDragOperation:(id)fp8;
- (void)smartInsertForString:(id)fp8 replacingRange:(struct _NSRange)fp12 beforeString:(id *)fp20 afterString:(id *)fp24;

@end

@interface BrowserWindowController : WindowController <ProvidesSearchTarget, ReopensAtLaunch>
{
    id locationBar;
    id favoritesBarView;
    id tabBarView;
    id backButton;
    id forwardButton;
    NSButton *homeButton;
    NSButton *addBookmarkButton;
    NSButton *autoFillButton;
    NSButton *fontSmallerButton;
    NSButton *fontBiggerButton;
    NSButton *stopAndReloadButton;
    id locationField;
    id searchField;
    id toggleBookmarksButton;
    NSTabView *tabSwitcher;
    id statusBar;
    id statusStringView;
    id _favoritesBar;
    id _toolbarController;
    LocationFieldEditor *_locationFieldEditor;
    id _searchFieldEditor;
    id _completionController;
    id _searchSuggestionController;
    BOOL _isLoading;
    BOOL _isLoadingCounterpartURLForRSS;
    BOOL _temporaryLocationBar;
    BOOL _editedLocationField;
    BOOL _editedLocationFieldWhileLoading;
    BOOL _editedSearchField;
    BOOL _nextSplitViewResizeIsProgrammatic;
    BOOL _tabBarHiddenByJavaScript;
    BOOL _readyToUpdateKeyboardLoop;
    NSMutableDictionary *_viewFramesForResizing;
    BOOL _favoritesBarShowing;
    BOOL _tabBarShowing;
    BOOL _statusBarShowing;
    BOOL _acceptsGenericIcon;
    NSString *_statusText;
    BOOL _clearStatus;
    BOOL _ellipsizeStatus;
    NSString *_newStatus;
    BOOL _stopAndReloadButtonWillStop;
    BOOL _tabBarInTransition;
    BOOL _parentalControlEnabled;
    NSTabView *_tabSwitcherForGoBack;
    NSTabView *_tabSwitcherForGoForward;
    BOOL _pendingProgressUpdate;
    NSURL *_pendingSearchURL;
    BOOL _RSSTransitionSlowMotion;
    id _RSSTransitionImageView;
    NSTimer *_RSSTransitionTimer;
    double _RSSTransitionStartTime;
    double _RSSTransitionDuration;
    BOOL _mainFrameDidFirstLayout;
    BOOL _startRSSAnimationAfterFirstLayout;
}

+ (int)windowPolicyFromEventModifierFlags:(unsigned int)fp8 requireCommandKey:(BOOL)fp12;
+ (int)windowPolicyFromEventModifierFlags:(unsigned int)fp8;
+ (int)windowPolicyFromCurrentEventRequireCommandKey:(BOOL)fp8;
+ (int)windowPolicyFromCurrentEvent;
+ (int)windowPolicyFromCurrentEventRespectingKeyEquivalents:(BOOL)fp8;
+ (void)reopen;
- (id)browserDocument;
- (id)currentWebView;
- (id)currentBookmarksViewController;
- (id)windowNibName;
- (id)locationField;
- (id)searchField;
- (void)_makeFirstResponder:(id)fp8;
- (void)_makeLocationFieldFirstResponder;
- (void)_makeSearchFieldFirstResponder;
- (BOOL)_searchFieldIsFirstResponder;
- (void)updateSearchSnapBackButton;
- (void)updateSnapBackButtons;
- (void)webViewPageForSnapBackHasChanged:(id)fp8;
- (void)setUpSearchField;
- (BOOL)locationBarIsShowing;
- (void)setUpLocationBar;
- (BOOL)isShowingBookmarks;
- (BOOL)allowBookmarksChanges;
- (BOOL)firstResponderIsDescendantOf:(id)fp8;
- (id)selectedTab;
- (id)mainWebFrameView;
- (BOOL)isShowingBar:(id)fp8;
- (void)updateKeyboardLoop;
- (void)collectViewFramesForResizing;
- (void)getTabLabel:(id *)fp8 andToolTip:(id *)fp12 forWebView:(id)fp16;
- (id)tabLabelForWebView:(id)fp8;
- (void)updateLabelForTab:(id)fp8 evenIfTabBarHidden:(BOOL)fp12;
- (void)updateLabelForTab:(id)fp8;
- (id)setUpTabForWebView:(id)fp8 addToRightSide:(BOOL)fp12;
- (id)setUpTabForWebView:(id)fp8;
- (BOOL)alwaysShowTabBar;
- (struct _NSRect)defaultFrame;
- (BOOL)searchFieldShouldShowGoogleSuggestions;
- (id)completionController;
- (id)searchSuggestionController;
- (void)_preloadImages;
- (void)windowWillLoad;
- (void)windowDidLoad;
- (BOOL)_windowIsFullHeight;
- (struct _NSRect)adjustedFrameForSaving:(struct _NSRect)fp8;
- (struct _NSRect)adjustedFrameForCascade:(struct _NSRect)fp8 fromWindow:(id)fp24;
- (struct _NSSize)windowWillResize:(id)fp8 toSize:(struct _NSSize)fp12;
- (void)windowDidResize:(id)fp8;
- (void)setDocumentEdited:(BOOL)fp8;
- (void)dealloc;
- (void)setDocument:(id)fp8;
- (void)stopLoading:(id)fp8;
- (void)cancel:(id)fp8;
- (BOOL)windowWillHandleKeyEvent:(id)fp8;
- (id)_computePriorFirstResponder;
- (void)locationTextFieldURLDropped:(id)fp8;
- (id)windowWillReturnFieldEditor:(id)fp8 toObject:(id)fp12;
- (struct _NSSize)bestWindowSizeForBookmarksOutline;
- (struct _NSSize)bestWindowSizeForCurrentPageWithDefaultSize:(struct _NSSize)fp8;
- (struct _NSRect)windowWillUseStandardFrame:(id)fp8 defaultFrame:(struct _NSRect)fp12;
- (id)windowURL;
- (id)locationFieldURL;
- (void)windowShouldGoToURL:(id)fp8;
- (void)toggleLocationBarWithoutSavingConfiguration;
- (void)showLocationBarTemporarilyIfHidden;
- (void)makeLocationBarPermanentIfTemporary;
- (void)hideLocationBarIfTemporary;
- (void)selectSearchField:(id)fp8;
- (BOOL)canShowInputFields;
- (BOOL)searchField:(id)fp8 shouldRememberSearchString:(id)fp12;
- (void)setPendingSearchURL:(id)fp8;
- (void)noResponderFor:(SEL)fp8;
- (void)performQuickSearch:(id)fp8;
- (void)webFrameLoadStarted:(id)fp8;
- (void)updateLocationFieldText;
- (void)updateSecureIcon;
- (void)updateRSSButton;
- (id)createIncomingImageForRSSTransition;
- (void)removeRSSTransitionImageViewAndDisplay:(BOOL)fp8;
- (void)cancelRSSAnimationAfterSpecificInterval;
- (void)cleanUpRSSAnimationAndDisplay:(BOOL)fp8;
- (void)advanceRSSAnimation;
- (void)startRSSAnimationWithSlowMotion:(BOOL)fp8;
- (void)installRSSTransitionImageView;
- (void)goToCounterpartURLForRSSWithSlowMotion:(BOOL)fp8;
- (void)webFrameLoadCommitted:(id)fp8;
- (void)startRSSAnimation;
- (void)startRSSAnimationForFrame:(id)fp8 error:(id)fp12;
- (void)startRSSAnimationAfterSpecificInterval;
- (void)webFrameLoadDidFirstLayout:(id)fp8;
- (void)webFrameLoadFinished:(id)fp8 withError:(id)fp12;
- (void)webFrame:(id)fp8 willPerformClientRedirectToURL:(id)fp12;
- (BOOL)shouldMakeFirstResponder:(id)fp8;
- (void)tryToAutofillPasswords:(id)fp8;
- (id)locationFieldText;
- (void)setLocationFieldText:(id)fp8;
- (void)selectLocationField:(id)fp8;
- (void)tryMultipleURLs:(id)fp8 windowPolicy:(int)fp12;
- (void)goToToolbarLocationWithWindowPolicy:(int)fp8;
- (void)goToToolbarLocation:(id)fp8;
- (BOOL)locationFieldIsEmpty;
- (BOOL)searchFieldIsEmpty;
- (BOOL)locationFieldTextIsCurrentURL;
- (BOOL)locationFieldTextIsLocationFieldURL;
- (BOOL)updateStopAndReloadButton;
- (void)updateToggleBookmarksButton;
- (void)setLoading:(BOOL)fp8;
- (BOOL)isAvailableForForcedLocationUsingWindowPolicy:(int)fp8;
- (void)reloadObeyingLocationField:(id)fp8;
- (void)stopOrReload:(id)fp8;
- (void)toggleShowBookmarks:(id)fp8;
- (void)newBookmarkFolder:(id)fp8;
- (void)editAddressOfFavorite:(id)fp8;
- (void)editContentsOfFavorite:(id)fp8;
- (void)editTitleOfFavorite:(id)fp8;
- (void)revealFavorite:(id)fp8;
- (void)deleteBookmark:(id)fp8;
- (void)editTitleOfBookmarksCollection:(id)fp8;
- (void)setUpFavoritesBar;
- (void)toggleBar:(id)fp8 withAnimation:(BOOL)fp12 isShowing:(char *)fp16;
- (void)toggleFavoritesBarWithAnimation:(BOOL)fp8;
- (void)toggleFavoritesBar:(id)fp8;
- (void)toggleToolbarIgnoringCurrentEvent:(id)fp8;
- (void)toggleLocationBar:(id)fp8;
- (void)setToolbarsVisible:(BOOL)fp8;
- (BOOL)anyToolbarsVisible;
- (void)toggleTabBarWithAnimation:(BOOL)fp8;
- (void)setUpTabBar;
- (void)showTab:(id)fp8;
- (void)showTabAtIndex:(int)fp8;
- (BOOL)moreThanOneTabShowing;
- (void)updateCloseKeyEquivalents;
- (id)createTabWithFrameName:(id)fp8 andShow:(BOOL)fp12 addToRightSide:(BOOL)fp16;
- (id)createTabWithFrameName:(id)fp8;
- (id)createInactiveTabWithFrameName:(id)fp8;
- (id)createTab;
- (id)createInactiveTab;
- (void)newTab:(id)fp8;
- (void)closeTab:(id)fp8;
- (void)closeCurrentTab:(id)fp8;
- (void)closeOtherTabs:(id)fp8;
- (void)closeInactiveTabs:(id)fp8;
- (void)reloadTabsMatchingURLs:(id)fp8;
- (void)tabBarView:(id)fp8 didClickTabViewItem:(id)fp12;
- (void)tabBarView:(id)fp8 didClickCloseButtonForTabViewItem:(id)fp12 mouseDownModifierFlags:(unsigned int)fp16;
- (void)willSelectTabViewItem;
- (void)didSelectTabViewItem;
- (void)tabView:(id)fp8 willSelectTabViewItem:(id)fp12;
- (void)tabView:(id)fp8 didSelectTabViewItem:(id)fp12;
- (void)selectNextTab:(id)fp8;
- (void)selectPreviousTab:(id)fp8;
- (id)findTabForWebView:(id)fp8;
- (void)selectTab:(id)fp8;
- (void)closeTabOrWindow:(id)fp8;
- (void)webViewNameHasChanged:(id)fp8;
- (id)tabBarView:(id)fp8 menuForEvent:(id)fp12;
- (id)tabBarView:(id)fp8 menuForButtonForTabViewItem:(id)fp12 event:(id)fp16;
- (id)tabBarView:(id)fp8 menuForClippedTabViewItems:(id)fp12;
- (void)selectClippedTabViewItem:(id)fp8;
- (void)closeTabFromMenu:(id)fp8;
- (void)closeOtherTabsFromMenu:(id)fp8;
- (void)reloadTab:(id)fp8;
- (void)reloadTabFromMenu:(id)fp8;
- (void)reloadAllTabs:(id)fp8;
- (BOOL)shouldShowTabBar;
- (void)updateTabBarVisibility;
- (void)reloadParentallyRestrictedFrames;
- (void)defaultsDidChange;
- (void)windowDidBecomeKey:(id)fp8;
- (void)fixFocusRingAroundLocationField;
- (void)windowDidResignKey:(id)fp8;
- (BOOL)shouldCloseDocument;
- (id)replaceTabSwitcher:(id)fp8;
- (void)releaseTabSwitcher:(id)fp8;
- (void)releaseTabSwitchersForBackForward;
- (void)replaceTabURLs:(id)fp8 usingTabLabelsFromBookmarks:(id)fp12;
- (void)updateTabLabelForWebView:(id)fp8;
- (void)webViewSheetRequestStatusHasChanged:(id)fp8;
- (void)webViewLoadingStatusHasChanged:(id)fp8;
- (id)orderedTabs;
- (void)tabBarView:(id)fp8 performDragOperationForTabViewItem:(id)fp12 URL:(id)fp16;
- (void)tabBarView:(id)fp8 performDragOperationForURL:(id)fp12 droppedOnRightSide:(BOOL)fp16;
- (void)setUpStatusBar;
- (void)toggleStatusBarWithAnimation:(BOOL)fp8;
- (void)toggleStatusBar:(id)fp8;
- (id)_defaultStatus;
- (void)clearStatus;
- (void)setStatusMessageNow;
- (void)setStatusMessage:(id)fp8 ellipsize:(BOOL)fp12;
- (void)updateStatusMessage;
- (void)webViewStatusMessageHasChanged:(id)fp8;
- (BOOL)isStatusBarVisible;
- (void)setStatusBarVisible:(BOOL)fp8;
- (BOOL)acceptsGenericIcon;
- (void)setAcceptsGenericIcon:(BOOL)fp8;
- (void)updateLocationFieldIcon;
- (void)controlTextDidChange:(id)fp8;
- (void)controlTextDidEndEditing:(id)fp8;
- (BOOL)control:(id)fp8 textView:(id)fp12 doCommandBySelector:(SEL)fp16;
- (void)updatePopUpCheckmark:(id)fp8;
- (float)splitView:(id)fp8 constrainMaxCoordinate:(float)fp12 ofSubviewAt:(int)fp16;
- (float)splitView:(id)fp8 constrainMinCoordinate:(float)fp12 ofSubviewAt:(int)fp16;
- (float)rememberCurrentInputFieldWidthRatioForSplitView:(id)fp8;
- (void)splitViewDidResizeSubviews:(id)fp8;
- (void)splitView:(id)fp8 resizeSubviewsWithOldSize:(struct _NSSize)fp12;
- (id)targetForSearch;
- (BOOL)goToBookmarks;
- (void)goBack:(id)fp8;
- (void)goForward:(id)fp8;
- (BOOL)canGoBack;
- (BOOL)canGoForward;
- (id)backListMenuForButton:(id)fp8;
- (id)forwardListMenuForButton:(id)fp8;
- (BOOL)canAddBookmark;
- (BOOL)canGoHome;
- (BOOL)canAutoFill;
- (BOOL)canPrintFromToolbar;
- (void)goHome:(id)fp8;
- (void)addBookmark:(id)fp8;
- (BOOL)canToggleShowSearchField;
- (void)toggleShowGoogleSearch:(id)fp8;
- (BOOL)canReloadObeyingLocationField;
- (BOOL)canReloadTab:(id)fp8;
- (BOOL)canReloadAllTabs;
- (BOOL)validateUserInterfaceItem:(id)fp8;
- (BOOL)validateMenuItem:(id)fp8;
- (void)changeTextEncoding:(id)fp8;
- (void)setSearchFieldText:(id)fp8;
- (id)searchFieldText;
- (void)searchForString:(id)fp8;
- (void)chooseSearchString:(id)fp8;
- (void)recentSearchesCleared:(id)fp8;
- (void)textFieldWithControlsPerformRightButtonAction:(id)fp8;
- (void)textFieldWithControlsPerformRightButton2Action:(id)fp8;
- (void)textFieldWithControls:(id)fp8 mouseUpInRightButton:(id)fp12;
- (void)textFieldWithControls:(id)fp8 mouseUpInRightButton2:(id)fp12;
- (id)bookmarkTitleForLocationField:(id)fp8;
- (void)setProgressBarValue:(double)fp8;
- (void)updateProgressBarNow;
- (void)updateProgressBar;
- (void)updateProgressBar:(BOOL)fp8;
- (void)showCompleteProgressBar;
- (void)clearProgressBar;
- (void)tellUserThatAppIsHosed;
- (void)showWindow:(id)fp8;
- (void)makeTextLarger:(id)fp8;
- (void)makeTextSmaller:(id)fp8;
- (void)reportBugToApple:(id)fp8;
- (void)printFromToolbar:(id)fp8;
- (void)autoFill:(id)fp8;

@end
