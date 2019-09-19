//
//  AdHubSDKDefines.h
//  Pods
//
//  Created by Cookie on 2019/9/5.
//

#import <Foundation/Foundation.h>

#if defined(__has_attribute)
#if __has_attribute(deprecated)
#define ADHUB_DEPRECATED_MSG_ATTRIBUTE(s) __attribute__((deprecated(s)))
#define ADHUB_DEPRECATED_ATTRIBUTE __attribute__((deprecated))
#else
#define ADHUB_DEPRECATED_MSG_ATTRIBUTE(s)
#define ADHUB_DEPRECATED_ATTRIBUTE
#endif
#else
#define ADHUB_DEPRECATED_MSG_ATTRIBUTE(s)
#define ADHUB_DEPRECATED_ATTRIBUTE
#endif
