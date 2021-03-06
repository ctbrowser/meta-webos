# Imported from oe-core e97d152ca13556b41a236c1a4cfb11e77ff857d7. Can be dropped
# once we move to Yocto 1.6 .

TUNEVALID[vfp] = "Enable Vector Floating Point (vfp) unit."
ARMPKGSFX_FPU .= "${@bb.utils.contains("TUNE_FEATURES", "vfp", "-vfp", "" ,d)}"

TUNEVALID[vfpv4] = "Enable Vector Floating Point Version 4 (vfpv4) unit."
ARMPKGSFX_FPU .= "${@bb.utils.contains("TUNE_FEATURES", "vfpv4", "-vfpv4", "" ,d)}"

TUNEVALID[callconvention-hard] = "Enable EABI hard float call convention, requires VFP."
TUNE_CCARGS .= "${@bb.utils.contains("TUNE_FEATURES", "vfp", bb.utils.contains("TUNE_FEATURES", "callconvention-hard", " -mfloat-abi=hard", " -mfloat-abi=softfp", d), "" ,d)}"
ARMPKGSFX_EABI .= "${@bb.utils.contains("TUNE_FEATURES", [ "callconvention-hard", "vfp" ], "hf", "", d)}"
