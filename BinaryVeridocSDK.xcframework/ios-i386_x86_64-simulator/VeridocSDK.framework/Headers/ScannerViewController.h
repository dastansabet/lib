
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, Language) {
    DEFAULT,
    KK,
    RU,
    EN
};

typedef NS_ENUM(NSInteger, DocumentType) {
    IdentityDocument = 0,
    Mrz = 1,
    Sim = 2,
};

typedef NS_ENUM(NSInteger, RecognitionWarning) {
    InconsistentBdAndIin = 0,
    GenderUnspecifiedInIin = 1
};

typedef NS_ENUM(NSInteger, RecognitionMode) {
    SingleImage = 0,
    TwoSidedDocument = 1
};

@protocol ScannerViewControllerDelegate <NSObject>

- (void) onSuccessCallback:(NSDictionary *) result;

- (void) onErrorCallback:(NSDictionary *) result;

- (void) onLogEventCallback:(NSDictionary *) result;

- (void) scannerSuspendedByUserAction;

@end

@interface ScannerViewController : UIViewController

@property (nonatomic, weak) id <ScannerViewControllerDelegate> delegate;
@property (nonatomic, assign) DocumentType type;
@property (nonatomic, assign) RecognitionMode recognitionMode;
@property (nonatomic, assign) Language language;
@property (getter = getIsTranslitCheckNeeded, setter = setIsTranslitCheckNeeded:) BOOL isTranslitCheckNeeded NS_SWIFT_NAME(isTranslitCheckNeeded);
@property (nonatomic, assign) BOOL isAutoDocTypeMode;
@property (nonatomic, assign) BOOL hideButton;
- (NSMutableArray *) getRecognitionWarnings;

@end
