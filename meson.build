project('gperf2json', 'cpp')
gperfsrc = include_directories('gperf-3.1/src')
gperflib = include_directories('gperf-3.1/lib')
executable(
  'gperf2json',
  'gperf2json.cc',
  'gperf-3.1/lib/getline.cc',
  'gperf-3.1/src/input.cc',
  'gperf-3.1/src/options.cc',
  'gperf-3.1/src/keyword.cc',
  'gperf-3.1/src/keyword-list.cc',
  'gperf-3.1/src/version.cc',
  include_directories : [ gperfsrc, gperflib ],
  install : true,
)
