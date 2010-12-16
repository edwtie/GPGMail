#import <Cocoa/Cocoa.h>

#ifdef SNOW_LEOPARD_64

@protocol DocumentEditorManaging
- (void)registerDocumentEditor:(id)arg1;
- (void)unregisterDocumentEditor:(id)arg1;
@end

@protocol MessageContentDisplay <NSObject>
+ (id)copyDocumentForMessage:(id) arg1 viewingState:(id)arg2;
- (id)contentView;
- (id)textView;
- (void)display:(id) arg1 inContainerView:(id) arg2 replacingView:(id) arg3 invokeWhenDisplayChanged:(id)arg4;
- (void)prepareToRemoveView;
- (void)highlightSearchText:(id)arg1;
- (id)selectedText;
- (id)selectedTextRepresentation;
- (void)setSelectedTextRepresentation:(id)arg1;
- (id)selectionParsedMessage;
- (id)attachmentsInSelection;
- (id)parsedMessage;
- (void)adjustFontSizeBy:(long long)arg1 viewingState:(id)arg2;
- (id)findTarget;
- (void)detectDataInMessage:(id) arg1 usingContext:(id)arg2;
- (void)cancelDataDetection;

@optional
- (BOOL)isOkayToDownloadAttachment:(id)arg1;
@property id delegate;
@end

@class Message;
@class ActivityMonitor;
@class MimeBody;
@class MFError;

@interface MessageViewingState : NSObject
{
	NSAttributedString * _headerAttributedString;
	NSDictionary * _addressAttachments;
	NSDictionary * _plainAddresses;
	NSSet * _expandedAddressKeys;
	NSAttributedString * _attachmentsDescription;
	NSArray * _headerOrder;
	NSArray * _attachments;
	Message * _message;
	ActivityMonitor * _monitor;
	MimeBody * mimeBody;
	id document;
	MFError * error;
	long long headerIndent;
	long long headerFontAdjustmentDebt;
	int preferredAlternative;
	BOOL accountWasOffline;
	BOOL dontCache;
	BOOL showAllHeaders;
	BOOL showDefaultHeaders;
	BOOL isPrinting;
	BOOL viewSource;
	BOOL showControlChars;
	BOOL showAttachments;
	BOOL downloadRemoteURLs;
	BOOL triedToDownloadRemoteURLs;
	BOOL messageIsFromMicrosoft;
	BOOL isChildRequestForSenders;
	int displayType;
	unsigned int preferredEncoding;
	NSString * sender;
	NSString * senderName;
	NSString * childAddress;
	NSArray * requestedAddressesFromChild;
	id <MessageContentDisplay> displayer;
	id editor;
}

+ (void)initialize;
- (void)release;
- (void)dealloc;
- (id)init;
@property (retain) id editor;
- (void)editorClosed:(id)arg1;
@property (retain, nonatomic) MimeBody * mimeBody; // @synthesize mimeBody;
@property (readonly) NSArray * attachments;
@property (retain) NSAttributedString * headerAttributedString;
@property (retain) NSDictionary * plainAddresses;
@property (retain) NSDictionary * addressAttachments;
@property (retain) NSSet * expandedAddressKeys;
@property (retain) NSAttributedString * attachmentsDescription;
@property (retain) NSArray * headerOrder;
@property (readonly) int headerDetailLevel;
- (id)description;
@property (retain) ActivityMonitor * monitor; // @synthesize monitor=_monitor;
@property (retain) Message * message; // @synthesize message=_message;
@property (retain, nonatomic) id <MessageContentDisplay> displayer; // @synthesize displayer;
@property (retain, nonatomic) NSArray * requestedAddressesFromChild; // @synthesize requestedAddressesFromChild;
@property (copy, nonatomic) NSString * childAddress; // @synthesize childAddress;
@property (copy, nonatomic) NSString * senderName; // @synthesize senderName;
@property (copy, nonatomic) NSString * sender; // @synthesize sender;
@property (nonatomic) unsigned int preferredEncoding; // @synthesize preferredEncoding;
@property (nonatomic) int displayType; // @synthesize displayType;
@property (nonatomic) BOOL isChildRequestForSenders; // @synthesize isChildRequestForSenders;
@property (nonatomic) BOOL messageIsFromMicrosoft; // @synthesize messageIsFromMicrosoft;
@property (nonatomic) BOOL triedToDownloadRemoteURLs; // @synthesize triedToDownloadRemoteURLs;
@property (nonatomic) BOOL downloadRemoteURLs; // @synthesize downloadRemoteURLs;
@property (nonatomic) BOOL showAttachments; // @synthesize showAttachments;
@property (nonatomic) BOOL showControlChars; // @synthesize showControlChars;
@property (nonatomic) BOOL viewSource; // @synthesize viewSource;
@property (nonatomic) BOOL isPrinting; // @synthesize isPrinting;
@property (nonatomic) BOOL showDefaultHeaders; // @synthesize showDefaultHeaders;
@property (nonatomic) BOOL showAllHeaders; // @synthesize showAllHeaders;
@property (nonatomic) BOOL dontCache; // @synthesize dontCache;
@property (nonatomic) BOOL accountWasOffline; // @synthesize accountWasOffline;
@property (nonatomic) int preferredAlternative; // @synthesize preferredAlternative;
@property (nonatomic) long long headerFontAdjustmentDebt; // @synthesize headerFontAdjustmentDebt;
@property (nonatomic) long long headerIndent; // @synthesize headerIndent;
@property (retain, nonatomic) MFError * error; // @synthesize error;
@property (retain, nonatomic) id document; // @synthesize document;

@end

@class TextMessageDisplay;
@class MessageHeaderDisplay;
@class HeaderAttachmentsView;
@class InvocationQueue;
@class ColorBackgroundView;
@class EmbeddedNoteDocumentEditor;
@class MessageBody;

@interface MessageContentController : NSResponder <DocumentEditorManaging>
{
	Message * _message;
	ActivityMonitor * _documentMonitor;
	ActivityMonitor * _urlificationMonitor;
	id <MessageContentDisplay> _currentDisplay;
	id <MessageContentDisplay> _threadDisplay;
	TextMessageDisplay * textDisplay;
	MessageHeaderDisplay * headerDisplay;
	NSView * contentContainerView;
	NSView * junkMailView;
	NSTextField * junkMailMessageField;
	NSButton * junkMailLoadHTMLButton;
	NSView * calendarBannerView;
	NSTextField * calendarEventTitle;
	NSTextField * calendarEventTime;
	NSButton * calendarOpeniCalButton;
	NSView * loadImagesView;
	NSView * certificateView;
	NSImageView * certificateImage;
	NSTextField * certificateMessageField;
	NSButton * certificateHelpButton;
	NSView * childBannerView;
	NSTextField * childBannerMessageField;
	NSImageView * childBannerImage;
	NSButton * childBannerButton;
	NSButton * childBannerHelpButton;
	NSView * parentBannerView;
	NSTextField * parentBannerMessageField;
	NSImageView * parentBannerImage;
	NSButton * parentBannerButton;
	HeaderAttachmentsView * attachmentsView;
	NSCache * _documentCache;
	InvocationQueue * invocationQueue;
	double _foregroundLoadStartTime;
	double _backgroundLoadStartTime;
	double _backgroundLoadEndTime;
	NSString * _messageIDToRestoreInitialStateFor;
	struct CGRect _initialVisibleRect;
	struct _NSRange _initialSelectedRange;
	NSArray * mostRecentHeaderOrder;
	NSTimer * _fadeTimer;
	ColorBackgroundView * _currentBanner;
	BOOL _hideBannerBorder;
	NSTextField * _widthResizableTextFieldInCurrentBanner;
	NSView * _rightNeighborOfWidthResizableTextFieldInCurrentBanner;
	BOOL isForPrinting;
	BOOL showDefaultHeadersStickily;
	MessageViewingState * stickyViewingState;
	MessageViewingState * _viewingState;
	NSMutableDictionary * _editorCache;
	EmbeddedNoteDocumentEditor * _currentEditor;
	double _accumulatedMagnification;
	BOOL _canZoomIn;
	BOOL _canZoomOut;
}

+ (void)setClass:(Class) arg1 forDisplayType:(id)arg2;
+ (id)keyPathsForValuesAffectingShouldHideMeetingRequestButtons;
+ (id)keyPathsForValuesAffectingShouldHideMeetingCancellationOKButton;
- (id)init;
- (id)documentEditors;
- (void)registerDocumentEditor:(id)arg1;
- (void)unregisterDocumentEditor:(id)arg1;
- (void)setIsForPrinting:(BOOL)arg1;
- (id)_documentCache;
- (void)setContentContainerView:(id)arg1;
- (void)setCalendarBannerView:(id)arg1;
- (void)setLoadImagesView:(id)arg1;
- (void)setJunkMailView:(id)arg1;
- (void)setCertificateView:(id)arg1;
- (void)setChildBannerView:(id)arg1;
- (void)setParentBannerView:(id)arg1;
- (void)readDefaultsFromDictionary:(id)arg1;
- (void)writeDefaultsToDictionary:(id)arg1;
@property (retain) NSMutableDictionary * editorCache; // @synthesize editorCache=_editorCache;
- (void)release;
- (void)dealloc;
- (void)_stopBackgroundMessageLoading:(BOOL) arg1 URLification:(BOOL) arg2 dataDetection:(BOOL)arg3;
- (void)stopAllActivity;
- (id)documentView;
- (id)bannerView;
- (id)currentDisplay;
- (void)_updateIfDisplayingMessage:(id)arg1;
@property (retain) MessageViewingState * viewingState;
- (void)_fetchDataForMessageAndUpdateDisplay:(id)arg1;
- (void)_messageMayHaveBecomeAvailable;
- (id)_messageTilingView;
- (void)fadeToEmpty;
- (void)_pushDocumentToCache;
- (void)_doUrlificationAndDataDetectionForViewingState:(id)arg1;
- (void)_backgroundLoadFinished:(id)arg1;
- (void)setMessage:(id) arg1 headerOrder:(id)arg2;
- (void)_setMessage:(id) arg1 headerOrder:(id)arg2;
- (void)fetchEditorForMessage:(id) arg1 viewingState:(id)arg2;
- (void)editorDidLoad:(id)arg1;
- (void)editorFailedLoad:(id)arg1;
- (id)existingEditor:(Class) arg1 forDocument:(id)arg2;
- (void)_fetchContentsForMessage:(id) arg1 fromStore:(id) arg2 withViewingState:(id)arg3;
- (BOOL)canAddNoteToMessage;
- (BOOL)canAddToDoToMessage;
- (void)webMessageController:(id) arg1 willDisplayMenuItems:(id)arg2;
- (void)addAssociatedToDo:(id)arg1;
- (void)_startBackgroundLoad:(id)arg1;
- (void)_setInvocationQueue:(id)arg1;
- (void)setMostRecentHeaderOrder:(id)arg1;
- (void)reloadCurrentMessage;
- (void)viewerPreferencesChanged:(id)arg1;
- (void)_removeCurrentBanner;
- (void)_bannerResized:(id)arg1;
- (void)_contentViewResized:(id)arg1;
- (void)_showBannerView:(id)arg1;
- (void)_showLoadImagesBanner;
- (void)_showCertificateBanner;
@property (readonly) BOOL shouldHideMeetingRequestButtons; // @dynamic shouldHideMeetingRequestButtons;
@property (readonly) BOOL shouldHideMeetingCancellationOKButton; // @dynamic shouldHideMeetingCancellationOKButton;
- (void)_showCalendarBanner;
- (id)_eventForCurrentMessage;
- (id)_titleForEvent:(id)arg1;
- (id)_dateStringForEvent:(id)arg1;
- (void)_showJunkBanner;
- (BOOL)_showBannerIfMessageIsOutgoingMessageWaitingForParentApproval;
- (BOOL)_showBannerIfMessageIsPermissionRequestFromChild;
- (void)_updateBanner;
- (void)setShowRevealMessageLink:(BOOL)arg1;
- (BOOL)showRevealMessageLink;
- (void)_addRecentAddress:(id)arg1;
- (void)markAsNotJunkMailClicked:(id)arg1;
- (void)_setJunkLevelToNotJunk;
- (void)approveChildRequest:(id)arg1;
- (void)rejectChildRequest:(id)arg1;
- (void)sendMeetingResponse:(id)arg1;
- (void)openIniCal:(id)arg1;
- (void)sendMessage:(id)arg1;
- (void)_messageFlagsDidChange:(id)arg1;
- (void)_messagesDidUpdate:(id)arg1;
- (void)closeEditors;
- (id)editorForNote:(id) arg1 message:(id)arg2;
- (id)editorForNote:(id) arg1 message:(id) arg2 isPaperless:(BOOL) arg3 willLoad:(char *)arg4;
- (void)_updateEditorDisplay;
- (id)_dataDetectorsContextForMessage:(id)arg1;
- (void)_updateDisplay;
- (void)editorClosed:(id)arg1;
@property (retain) EmbeddedNoteDocumentEditor * currentEditor; // @synthesize currentEditor=_currentEditor;
- (void)_setCurrentDisplay:(id)arg1;
- (void)_displayChanged;
- (void)highlightSearchText:(id)arg1;
- (id)attachmentsView;
- (id)textView;
- (id)selectedText;
- (id)selectionParsedMessage;
- (id)attachmentsInSelection;
- (id)parsedMessage;
- (void)clearCache;
- (void)clearCacheForMessage:(id)arg1;
- (void)removeCacheObjectForKey:(id)arg1;
- (void)setCacheObject:(id) arg1 forKey:(id)arg2;
- (id)cacheObjectForKey:(id)arg1;
- (id)viewingStateForMessage:(id)arg1;
- (void)cacheViewingState:(id) arg1 forMessage:(id)arg2;
- (void)initPrintInfo;
- (int)headerDetailLevel;
- (BOOL)showingAllHeaders;
- (void)setShowAllHeaders:(BOOL)arg1;
- (BOOL)remoteAttachmentsAreDownloaded;
- (void)makeStickyInfoFromViewingState:(id)arg1;
- (void)makeStickyShowDefaultHeaders;
- (void)keyDown:(id)arg1;
- (void)resetGestureState;
- (void)beginGestureWithEvent:(id)arg1;
- (void)endGestureWithEvent:(id)arg1;
- (void)magnifyWithEvent:(id)arg1;
- (BOOL)pageDown;
- (BOOL)pageUp;
- (BOOL)currentlyViewingSource;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (id)findTarget;
- (BOOL)validateToolbarItem:(id)arg1;
- (BOOL)validateMenuItem:(id)arg1;
- (void)showAllHeaders:(id)arg1;
- (void)showFilteredHeaders:(id)arg1;
- (void)viewSource:(id)arg1;
- (void)toggleShowControlCharacters:(id)arg1;
- (void)showFirstAlternative:(id)arg1;
- (void)showPreviousAlternative:(id)arg1;
- (void)showNextAlternative:(id)arg1;
- (void)_messageWouldHaveLoadedRemoteURL:(id)arg1;
- (void)downloadRemoteContent:(id)arg1;
- (void)showCertificate:(id)arg1;
- (void)certificateTrustSheetDidEnd:(id) arg1 returnCode:(long long)arg2 contextInfo:(void *)arg3;
- (void)showBestAlternative:(id)arg1;
- (void)changeTextEncoding:(id)arg1;
- (void)makeFontBigger:(id)arg1;
- (void)makeFontSmaller:(id)arg1;
- (void)jumpToSelection:(id)arg1;
- (void)takeFindStringFromSelection:(id)arg1;
- (void)saveAttachments:(id)arg1;
- (void)saveAttachmentsWithoutPrompting:(id)arg1;
@property (retain, nonatomic) Message * message; // @synthesize message=_message;
@property (retain) ActivityMonitor * urlificationMonitor; // @synthesize urlificationMonitor=_urlificationMonitor;
@property (retain) ActivityMonitor * documentMonitor; // @synthesize documentMonitor=_documentMonitor;

@end

#elif defined(SNOW_LEOPARD)

@class Message;
@class ActivityMonitor;
@class MimeBody;
@class MFError;
@class TextMessageDisplay;
@class MessageHeaderDisplay;
@class HeaderAttachmentsView;
@class NSCache;
@class InvocationQueue;
@class ColorBackgroundView;
@class EmbeddedNoteDocumentEditor;

@protocol DocumentEditorManaging
- (void)registerDocumentEditor:(id)arg1;
- (void)unregisterDocumentEditor:(id)arg1;
@end

@protocol MessageContentDisplay <NSObject>
+ (id)copyDocumentForMessage:(id) arg1 viewingState:(id)arg2;
- (id)contentView;
- (id)textView;
- (void)display:(id) arg1 inContainerView:(id) arg2 replacingView:(id) arg3 invokeWhenDisplayChanged:(id)arg4;
- (void)prepareToRemoveView;
- (void)highlightSearchText:(id)arg1;
- (id)selectedText;
- (id)selectedTextRepresentation;
- (void)setSelectedTextRepresentation:(id)arg1;
- (id)selectionParsedMessage;
- (id)attachmentsInSelection;
- (id)parsedMessage;
- (void)adjustFontSizeBy:(long)arg1 viewingState:(id)arg2;
- (id)findTarget;
- (void)detectDataInMessage:(id) arg1 usingContext:(id)arg2;
- (void)cancelDataDetection;
@end

@interface MessageViewingState : NSObject
{
	NSAttributedString * _headerAttributedString;
	NSDictionary * _addressAttachments;
	NSDictionary * _plainAddresses;
	NSSet * _expandedAddressKeys;
	NSAttributedString * _attachmentsDescription;
	NSArray * _headerOrder;
	NSArray * _attachments;
	Message * _message;
	ActivityMonitor * _monitor;
	MimeBody * mimeBody;
	id document;
	MFError * error;
	int headerIndent;
	int headerFontAdjustmentDebt;
	int preferredAlternative;
	BOOL accountWasOffline;
	BOOL dontCache;
	BOOL showAllHeaders;
	BOOL showDefaultHeaders;
	BOOL isPrinting;
	BOOL viewSource;
	BOOL showControlChars;
	BOOL showAttachments;
	BOOL downloadRemoteURLs;
	BOOL triedToDownloadRemoteURLs;
	BOOL messageIsFromMicrosoft;
	BOOL isChildRequestForSenders;
	int displayType;
	unsigned int preferredEncoding;
	NSString * sender;
	NSString * senderName;
	NSString * childAddress;
	NSArray * requestedAddressesFromChild;
	id <MessageContentDisplay> displayer;
	id editor;
}

+ (void)initialize;
- (void)release;
- (void)dealloc;
- (id)init;
- (id)editor;
- (void)setEditor:(id)arg1;
- (void)editorClosed:(id)arg1;
- (id)mimeBody;
- (id)attachments;
- (id)headerAttributedString;
- (void)setHeaderAttributedString:(id)arg1;
- (id)plainAddresses;
- (void)setPlainAddresses:(id)arg1;
- (id)addressAttachments;
- (void)setAddressAttachments:(id)arg1;
- (id)expandedAddressKeys;
- (void)setExpandedAddressKeys:(id)arg1;
- (id)attachmentsDescription;
- (void)setAttachmentsDescription:(id)arg1;
- (id)headerOrder;
- (void)setHeaderOrder:(id)arg1;
- (int)headerDetailLevel;
- (id)description;
- (id)monitor;
- (void)setMonitor:(id)arg1;
- (id)message;
- (void)setMessage:(id)arg1;
- (id)displayer;
- (void)setDisplayer:(id)arg1;
- (id)requestedAddressesFromChild;
- (void)setRequestedAddressesFromChild:(id)arg1;
- (id)childAddress;
- (void)setChildAddress:(id)arg1;
- (id)senderName;
- (void)setSenderName:(id)arg1;
- (id)sender;
- (void)setSender:(id)arg1;
- (unsigned long)preferredEncoding;
- (void)setPreferredEncoding:(unsigned long)arg1;
- (int)displayType;
- (void)setDisplayType:(int)arg1;
- (BOOL)isChildRequestForSenders;
- (void)setIsChildRequestForSenders:(BOOL)arg1;
- (BOOL)messageIsFromMicrosoft;
- (void)setMessageIsFromMicrosoft:(BOOL)arg1;
- (BOOL)triedToDownloadRemoteURLs;
- (void)setTriedToDownloadRemoteURLs:(BOOL)arg1;
- (BOOL)downloadRemoteURLs;
- (void)setDownloadRemoteURLs:(BOOL)arg1;
- (BOOL)showAttachments;
- (void)setShowAttachments:(BOOL)arg1;
- (BOOL)showControlChars;
- (void)setShowControlChars:(BOOL)arg1;
- (BOOL)viewSource;
- (void)setViewSource:(BOOL)arg1;
- (BOOL)isPrinting;
- (void)setIsPrinting:(BOOL)arg1;
- (BOOL)showDefaultHeaders;
- (void)setShowDefaultHeaders:(BOOL)arg1;
- (BOOL)showAllHeaders;
- (void)setShowAllHeaders:(BOOL)arg1;
- (BOOL)dontCache;
- (void)setDontCache:(BOOL)arg1;
- (BOOL)accountWasOffline;
- (void)setAccountWasOffline:(BOOL)arg1;
- (int)preferredAlternative;
- (void)setPreferredAlternative:(int)arg1;
- (long)headerFontAdjustmentDebt;
- (void)setHeaderFontAdjustmentDebt:(long)arg1;
- (long)headerIndent;
- (void)setHeaderIndent:(long)arg1;
- (id)error;
- (void)setError:(id)arg1;
- (id)document;
- (void)setDocument:(id)arg1;
- (void)setMimeBody:(id)arg1;

@end

@interface MessageContentController : NSResponder <DocumentEditorManaging>
{
	Message * _message;
	ActivityMonitor * _documentMonitor;
	ActivityMonitor * _urlificationMonitor;
	id <MessageContentDisplay> _currentDisplay;
	id <MessageContentDisplay> _threadDisplay;
	TextMessageDisplay * textDisplay;
	MessageHeaderDisplay * headerDisplay;
	NSView * contentContainerView;
	NSView * junkMailView;
	NSTextField * junkMailMessageField;
	NSButton * junkMailLoadHTMLButton;
	NSView * calendarBannerView;
	NSTextField * calendarEventTitle;
	NSTextField * calendarEventTime;
	NSButton * calendarOpeniCalButton;
	NSView * loadImagesView;
	NSView * certificateView;
	NSImageView * certificateImage;
	NSTextField * certificateMessageField;
	NSButton * certificateHelpButton;
	NSView * childBannerView;
	NSTextField * childBannerMessageField;
	NSImageView * childBannerImage;
	NSButton * childBannerButton;
	NSButton * childBannerHelpButton;
	NSView * parentBannerView;
	NSTextField * parentBannerMessageField;
	NSImageView * parentBannerImage;
	NSButton * parentBannerButton;
	HeaderAttachmentsView * attachmentsView;
	NSCache * _documentCache;
	InvocationQueue * invocationQueue;
	double _foregroundLoadStartTime;
	double _backgroundLoadStartTime;
	double _backgroundLoadEndTime;
	NSString * _messageIDToRestoreInitialStateFor;
	struct CGRect _initialVisibleRect;
	struct _NSRange _initialSelectedRange;
	NSArray * mostRecentHeaderOrder;
	NSTimer * _fadeTimer;
	ColorBackgroundView * _currentBanner;
	BOOL _hideBannerBorder;
	NSTextField * _widthResizableTextFieldInCurrentBanner;
	NSView * _rightNeighborOfWidthResizableTextFieldInCurrentBanner;
	BOOL isForPrinting;
	BOOL showDefaultHeadersStickily;
	MessageViewingState * stickyViewingState;
	MessageViewingState * _viewingState;
	NSMutableDictionary * _editorCache;
	EmbeddedNoteDocumentEditor * _currentEditor;
	float _accumulatedMagnification;
	BOOL _canZoomIn;
	BOOL _canZoomOut;
}

+ (void)setClass:(Class) arg1 forDisplayType:(id)arg2;
+ (id)keyPathsForValuesAffectingShouldHideMeetingRequestButtons;
+ (id)keyPathsForValuesAffectingShouldHideMeetingCancellationOKButton;
- (id)init;
- (id)documentEditors;
- (void)registerDocumentEditor:(id)arg1;
- (void)unregisterDocumentEditor:(id)arg1;
- (void)setIsForPrinting:(BOOL)arg1;
- (id)_documentCache;
- (void)setContentContainerView:(id)arg1;
- (void)setCalendarBannerView:(id)arg1;
- (void)setLoadImagesView:(id)arg1;
- (void)setJunkMailView:(id)arg1;
- (void)setCertificateView:(id)arg1;
- (void)setChildBannerView:(id)arg1;
- (void)setParentBannerView:(id)arg1;
- (void)readDefaultsFromDictionary:(id)arg1;
- (void)writeDefaultsToDictionary:(id)arg1;
- (void)setEditorCache:(id)arg1;
- (void)release;
- (void)dealloc;
- (void)_stopBackgroundMessageLoading:(BOOL) arg1 URLification:(BOOL) arg2 dataDetection:(BOOL)arg3;
- (void)stopAllActivity;
- (id)documentView;
- (id)bannerView;
- (id)currentDisplay;
- (void)_updateIfDisplayingMessage:(id)arg1;
- (id)viewingState;
- (void)setViewingState:(id)arg1;
- (void)_fetchDataForMessageAndUpdateDisplay:(id)arg1;
- (void)_messageMayHaveBecomeAvailable;
- (id)_messageTilingView;
- (void)fadeToEmpty;
- (void)_pushDocumentToCache;
- (void)_doUrlificationAndDataDetectionForViewingState:(id)arg1;
- (void)_backgroundLoadFinished:(id)arg1;
- (void)setMessage:(id) arg1 headerOrder:(id)arg2;
- (void)_setMessage:(id) arg1 headerOrder:(id)arg2;
- (void)fetchEditorForMessage:(id) arg1 viewingState:(id)arg2;
- (void)editorDidLoad:(id)arg1;
- (void)editorFailedLoad:(id)arg1;
- (id)existingEditor:(Class) arg1 forDocument:(id)arg2;
- (void)_fetchContentsForMessage:(id) arg1 fromStore:(id) arg2 withViewingState:(id)arg3;
- (BOOL)canAddNoteToMessage;
- (BOOL)canAddToDoToMessage;
- (void)webMessageController:(id) arg1 willDisplayMenuItems:(id)arg2;
- (void)addAssociatedToDo:(id)arg1;
- (void)_startBackgroundLoad:(id)arg1;
- (void)_setInvocationQueue:(id)arg1;
- (void)setMostRecentHeaderOrder:(id)arg1;
- (void)reloadCurrentMessage;
- (void)viewerPreferencesChanged:(id)arg1;
- (void)_removeCurrentBanner;
- (void)_bannerResized:(id)arg1;
- (void)_contentViewResized:(id)arg1;
- (void)_showBannerView:(id)arg1;
- (void)_showLoadImagesBanner;
- (void)_showCertificateBanner;
- (BOOL)shouldHideMeetingRequestButtons;
- (BOOL)shouldHideMeetingCancellationOKButton;
- (void)_showCalendarBanner;
- (id)_eventForCurrentMessage;
- (id)_titleForEvent:(id)arg1;
- (id)_dateStringForEvent:(id)arg1;
- (void)_showJunkBanner;
- (BOOL)_showBannerIfMessageIsOutgoingMessageWaitingForParentApproval;
- (BOOL)_showBannerIfMessageIsPermissionRequestFromChild;
- (void)_updateBanner;
- (void)setShowRevealMessageLink:(BOOL)arg1;
- (BOOL)showRevealMessageLink;
- (void)_addRecentAddress:(id)arg1;
- (void)markAsNotJunkMailClicked:(id)arg1;
- (void)_setJunkLevelToNotJunk;
- (void)approveChildRequest:(id)arg1;
- (void)rejectChildRequest:(id)arg1;
- (void)sendMeetingResponse:(id)arg1;
- (void)openIniCal:(id)arg1;
- (void)sendMessage:(id)arg1;
- (void)_messageFlagsDidChange:(id)arg1;
- (void)_messagesDidUpdate:(id)arg1;
- (void)closeEditors;
- (id)editorForNote:(id) arg1 message:(id)arg2;
- (id)editorForNote:(id) arg1 message:(id) arg2 isPaperless:(BOOL) arg3 willLoad:(char *)arg4;
- (void)_updateEditorDisplay;
- (id)_dataDetectorsContextForMessage:(id)arg1;
- (void)_updateDisplay;
- (void)editorClosed:(id)arg1;
- (void)setCurrentEditor:(id)arg1;
- (void)_setCurrentDisplay:(id)arg1;
- (void)_displayChanged;
- (void)highlightSearchText:(id)arg1;
- (id)attachmentsView;
- (id)textView;
- (id)selectedText;
- (id)selectionParsedMessage;
- (id)attachmentsInSelection;
- (id)parsedMessage;
- (void)clearCache;
- (void)clearCacheForMessage:(id)arg1;
- (void)removeCacheObjectForKey:(id)arg1;
- (void)setCacheObject:(id) arg1 forKey:(id)arg2;
- (id)cacheObjectForKey:(id)arg1;
- (id)viewingStateForMessage:(id)arg1;
- (void)cacheViewingState:(id) arg1 forMessage:(id)arg2;
- (void)initPrintInfo;
- (int)headerDetailLevel;
- (BOOL)showingAllHeaders;
- (void)setShowAllHeaders:(BOOL)arg1;
- (BOOL)remoteAttachmentsAreDownloaded;
- (void)makeStickyInfoFromViewingState:(id)arg1;
- (void)makeStickyShowDefaultHeaders;
- (void)keyDown:(id)arg1;
- (void)resetGestureState;
- (void)beginGestureWithEvent:(id)arg1;
- (void)endGestureWithEvent:(id)arg1;
- (void)magnifyWithEvent:(id)arg1;
- (BOOL)pageDown;
- (BOOL)pageUp;
- (BOOL)currentlyViewingSource;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (id)findTarget;
- (BOOL)validateToolbarItem:(id)arg1;
- (BOOL)validateMenuItem:(id)arg1;
- (void)showAllHeaders:(id)arg1;
- (void)showFilteredHeaders:(id)arg1;
- (void)viewSource:(id)arg1;
- (void)toggleShowControlCharacters:(id)arg1;
- (void)showFirstAlternative:(id)arg1;
- (void)showPreviousAlternative:(id)arg1;
- (void)showNextAlternative:(id)arg1;
- (void)_messageWouldHaveLoadedRemoteURL:(id)arg1;
- (void)downloadRemoteContent:(id)arg1;
- (void)showCertificate:(id)arg1;
- (void)certificateTrustSheetDidEnd:(id) arg1 returnCode:(long)arg2 contextInfo:(void *)arg3;
- (void)showBestAlternative:(id)arg1;
- (void)changeTextEncoding:(id)arg1;
- (void)makeFontBigger:(id)arg1;
- (void)makeFontSmaller:(id)arg1;
- (void)jumpToSelection:(id)arg1;
- (void)takeFindStringFromSelection:(id)arg1;
- (void)saveAttachments:(id)arg1;
- (void)saveAttachmentsWithoutPrompting:(id)arg1;
- (id)message;
- (void)setMessage:(id)arg1;
- (id)urlificationMonitor;
- (void)setUrlificationMonitor:(id)arg1;
- (id)documentMonitor;
- (void)setDocumentMonitor:(id)arg1;
- (id)currentEditor;
- (id)editorCache;

@end

#endif // ifdef SNOW_LEOPARD_64
