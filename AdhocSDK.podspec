Pod::Spec.new do |s|
  s.name         = "AdhocSDK"
  s.version      = "3.0.1"
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
  s.platform     = :ios, "7.0"
  s.source  = {
    :git => "https://github.com/AppAdhoc/AdhocSDK-iOS.git",
    :tag => "3.0.1"
  }
  
  s.preserve_paths = 'AdhocSDK.framework'
  s.vendored_frameworks = 'AdhocSDK.framework'
  s.frameworks = "SystemConfiguration", "Security"
  s.libraries = "sqlite3", "icucore"
  s.requires_arc = true

end
