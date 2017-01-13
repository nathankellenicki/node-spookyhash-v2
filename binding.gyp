{
    "targets": [{
        "target_name": "spookyhash-v2",
        "defines": ["V8_DEPRECATION_WARNINGS=1"],
        "sources": ["SpookyV2.cpp", "spookyhash-v2.cpp"],
        "include_dirs": [
            "<!(node -e \"require('nan')\")"
        ]
    }]
}
