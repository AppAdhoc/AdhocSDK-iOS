Pod::Spec.new do |s|
  s.name         = "AdhocSDK"
  s.version      = "5.2.6"
  s.summary      = "Official AdhocSDK for iOS."
  s.description  = <<-DESC
                   The Adhoc static lib for iOS makes it easy for A/B test.
                   DESC
  s.homepage     = "https://www.appadhoc.com/"
  s.license  = {
    :type => 'Commercial',
    :text => 'See https://www.appadhoc.com/clause.html'
  }
  s.author    = { "Adhoc" => "info@appadhoc.com" }
  s.platform     = :ios, "8.0"
  s.source  = {
    :git => "https://github.com/AppAdhoc/AdhocSDK-iOS.git",
    :tag => s.version
  }
  
  s.preserve_paths = 'AdhocSDK.framework'
  s.vendored_frameworks = 'AdhocSDK.framework'
  s.frameworks = "SystemConfiguration", "Security", "CFNetwork", "CoreTelephony", "AdSupport", "AVFoundation"
  s.libraries = "sqlite3", "icucore"
  s.requires_arc = true
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

end
