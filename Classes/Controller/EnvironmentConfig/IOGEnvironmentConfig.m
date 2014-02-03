//
//  IOGEnvironmentConfig.m
//  
//
//  Created by Vincil Bishop on 9/11/12.
//  Copyright (c) 2012. All rights reserved.
//

#import "IOGEnvironmentConfig.h"
#import "NSDictionary+IOG_Merge.h"

@interface IOGEnvironmentConfig ()

@property (nonatomic,strong) NSBundle *resourceBundle;
@property (nonatomic,strong) NSString *infoPListEnvironmentKey;
@property (nonatomic,strong) NSString *environmentPListFilename;
@property (nonatomic,strong) NSString *defaultConfigurationKey;

@end

@implementation IOGEnvironmentConfig

- (id)initWithPListFilename:(NSString*)environmentPListFilename environmentKey:(NSString*)infoPListEnvironmentKey defaultConfigKey:(NSString*)defaultConfigurationKey resourceBundle:(NSBundle*)resourceBundle
{
    self = [super init];
    
    if (self) {
        _resourceBundle = resourceBundle;
        _infoPListEnvironmentKey = infoPListEnvironmentKey;
        _defaultConfigurationKey = defaultConfigurationKey;
        _environmentPListFilename = environmentPListFilename;
        [self loadEnvironmentConfig];
    }
    
    return self;
}

- (id)initWithPListFilename:(NSString*)environmentPListFilename
{
    self = [self initWithPListFilename:environmentPListFilename environmentKey:nil defaultConfigKey:nil resourceBundle:nil];
    
    if (self) {
        
    }
    
    return self;
}

#pragma mark - Environment Config -

- (void) loadEnvironmentConfig
{
    if (!self.resourceBundle) {
        self.resourceBundle = [NSBundle bundleForClass:[self class]];
    }
    
    if (!self.defaultConfigurationKey) {
        self.defaultConfigurationKey = @"Defaults";
    }
    
    if (!self.infoPListEnvironmentKey) {
        self.infoPListEnvironmentKey = @"Environment";
    }
    
    NSString* configurationDict = [[self.resourceBundle infoDictionary] objectForKey:self.infoPListEnvironmentKey];
    NSBundle* bundle = self.resourceBundle;
    NSString* envsPListPath = [bundle pathForResource:self.environmentPListFilename ofType:nil];
    NSDictionary* environments = [[NSDictionary alloc] initWithContentsOfFile:envsPListPath];
    NSDictionary* environment = [environments objectForKey:configurationDict];
    
    // Let's coimbine values with the default config
    NSDictionary *defaultValues = [environments valueForKeyPath:self.defaultConfigurationKey];
    
    NSDictionary *combinedValues = [defaultValues PS_dictionaryByMergingWith:environment];
    
    _configValues = combinedValues;

}

#pragma mark - Helper Methods -

- (id) configValueForKey:(NSString*)key
{
    id value = [self.configValues valueForKey:key];
    
    if (!value) {
        // It can be hard to find when a value is missing, let's give oursleves a hint...
        NSString *errorMessage = [NSString stringWithFormat:@"Config Key [%@] not found in environment configuration!!!",key];
        DDLogError(@"%@",errorMessage);
    }

    return value;
}

@end
