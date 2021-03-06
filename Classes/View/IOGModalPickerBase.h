//
//  IOGModalPickerBase.h
//  CustomPicker
//
//

#define IOGMODALPICKER_PANEL_HEIGHT 260
#define IOGMODALPICKER_TOOLBAR_HEIGHT 44
#define IOGMODALPICKER_BACKDROP_OPACITY 0.8

#import <UIKit/UIKit.h>

@class IOGModalPickerView;
@class IOGModalDatePickerView;

typedef void (^IOGModalPickerViewCallback)(IOGModalPickerView *pickerView, BOOL madeChoice);
typedef void (^IOGModalDatePickerViewCallback)(IOGModalDatePickerView *datePickerView, BOOL madeChoice);

@interface IOGModalPickerBase : UIView {
    UIView* _picker;
}

@property (nonatomic, strong) UIToolbar *toolbar;
@property (nonatomic, strong) UIView *panel;
@property (nonatomic, strong) UIView *backdropView;
@property (nonatomic, strong) IOGModalPickerViewCallback callbackBlock;
@property (nonatomic, strong) IOGModalDatePickerViewCallback dateCallbackBlock;
@property (nonatomic, strong) NSArray *values;

@property (nonatomic, strong) UIView *picker;

/* Determines whether to display the opaque backdrop view.  By default, this is YES. */
@property (nonatomic) BOOL presentBackdropView;

/* Presents the control embedded in the provided view.
 Arguments:
   view        - The view that will contain the control.
   callback    - The block that will receive the result of the user action. 
 */
- (void)presentInView:(UIView *)view;

/* Presents the control embedded in the window.
 Arguments:
   callback    - The block that will receive the result of the user action. 
 */
- (void)presentInWindow;

/* Subclasses must override this method.  Subclasses implementations must NOT call super. */
- (UIView *)pickerWithFrame:(CGRect)pickerFrame;

/* Events that may be overridden in subclasses */
- (void)onDone:(id)sender;
- (void)onCancel:(id)sender;
- (void)onBackdropTap:(id)sender;

/* Override and return any additional buttons that you want on the toolbar.  By default, this is just a flexible space item. */
- (NSArray *)additionalToolbarItems;
    
@end
