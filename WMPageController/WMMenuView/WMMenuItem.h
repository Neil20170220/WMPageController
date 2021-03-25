//
//  WMMenuItem.h
//  WMPageController
//
//  Created by Mark on 15/4/26.
//  Copyright (c) 2015年 yq. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, WMMenuItemState) {
    WMMenuItemStateSelected,
    WMMenuItemStateNormal,
};

@protocol WMMenuItem;

@protocol WMMenuItemDelegate <NSObject>
@optional
- (void)didPressedMenuItem:(UIView<WMMenuItem> *)menuItem;
@end

@protocol WMMenuItem <NSObject>

@property (nonatomic, copy, nullable) NSString *text;
@property (nonatomic, copy, nullable) NSAttributedString *attributedText;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic) NSTextAlignment textAlignment;

@property (nonatomic, assign) CGFloat rate;
@property (nonatomic, assign) CGFloat normalSize;
@property (nonatomic, assign) CGFloat selectedSize;
@property (nonatomic, strong) UIColor *normalColor;
@property (nonatomic, strong) UIColor *selectedColor;
@property (nonatomic, assign) CGFloat speedFactor;
@property (nonatomic, nullable, weak) id<WMMenuItemDelegate> delegate;
@property (nonatomic, assign, readonly) BOOL selected;

- (instancetype)initWithFrame:(CGRect)frame;
- (void)setSelected:(BOOL)selected withAnimation:(BOOL)animation;

@end

@class WMMenuItem;

@interface WMMenuItem : UILabel <WMMenuItem>

@property (nonatomic, assign) CGFloat rate;           ///> 设置 rate, 并刷新标题状态 (0~1)
@property (nonatomic, assign) CGFloat normalSize;     ///> Normal状态的字体大小，默认大小为15
@property (nonatomic, assign) CGFloat selectedSize;   ///> Selected状态的字体大小，默认大小为18
@property (nonatomic, strong) UIColor *normalColor;   ///> Normal状态的字体颜色，默认为黑色 (可动画)
@property (nonatomic, strong) UIColor *selectedColor; ///> Selected状态的字体颜色，默认为红色 (可动画)
@property (nonatomic, assign) CGFloat speedFactor;    ///> 进度条的速度因数，默认 15，越小越快, 必须大于0
@property (nonatomic, nullable, weak) id<WMMenuItemDelegate> delegate;
@property (nonatomic, assign, readonly) BOOL selected;

@end
NS_ASSUME_NONNULL_END
