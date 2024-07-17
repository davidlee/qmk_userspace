task :compile do
  sh "qmk compile -kb boardsource/lulu/rp2040 -km davidlee"
end

task :flash do
  sh "qmk flash -kb boardsource/lulu/rp2040 -km davidlee"
end

task :default => :compile
