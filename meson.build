project('gperf2json', 'cpp')
gperf = get_option('gperf')
incdir = include_directories(f'@gperf@/src', f'@gperf@/lib')
nlohmann_json = dependency('nlohmann_json')
executable(
  'gperf2json',
  'gperf2json.cc',
  f'@gperf@/lib/getline.cc',
  f'@gperf@/src/input.cc',
  f'@gperf@/src/options.cc',
  f'@gperf@/src/keyword.cc',
  f'@gperf@/src/keyword-list.cc',
  f'@gperf@/src/version.cc',
  include_directories : incdir,
  dependencies : [ nlohmann_json ],
  install : true,
)
