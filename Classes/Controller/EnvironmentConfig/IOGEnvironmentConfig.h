//
//  PSEnvironmentConfig.h
//  
//
//  Created by Vincil Bishop on 9/11/12.
//  Copyright (c) 2012. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
	A utility class that provides configuration values from a .plist based on build configuration.
    @discussion Consider subclassing and implementing as a singleton.
 */
@interface IOGEnvironmentConfig : NSObject


@property (nonatomic,readonly) NSDictionary *configValues;

/**
	Initializes the instance with property values.
	@param environmentPListFilename The PList filename to load build configuration specific values from. A value must be supplied for this parameter.
	@param infoPListEnvironmentKey The key in the info.plist file that will convey the current build configuration. Passing nil will use the default value of "Environment".
	@param defaultConfigurationKey The top level key in the environmentPListFilename that will be used for default values. Passing nil will use the default value of "Defaults".
	@param resourceBundle The resource bundle containing the environmentPListFilename. Passing nil will use the default value of [NSBundle mainBundle].
	@returns An initialized instance.
 */
- (id)initWithPListFilename:(NSString*)environmentPListFilename environmentKey:(NSString*)infoPListEnvironmentKey defaultConfigKey:(NSString*)defaultConfigurationKey resourceBundle:(NSBundle*)resourceBundle
;

/**
	Initializes the instance with property values.
	@param environmentPListFilename The PList filename to load build configuration specific values from. A value must be supplied for this parameter.
	@returns An initialized instance.
 */
- (id)initWithPListFilename:(NSString*)environmentPListFilename
;

/**
	Retrieves a confuration value from the configValues dictionary, based on the current build configuration of course.
	@param key The key from the environmentPListFilename to
	@returns The value associated with the current build configuration.
 */
- (id) configValueForKey:(NSString*)key
;

@end
