Gem::Specification.new do |s|
  s.name    = 'calc_mzabala1'
  s.version = '0.1.0'
  s.date    = '2015-11-12'
  s.summary = 'Another calculator in ruby'
  s.description = 'An calculator implementation on ruby'
  s.author  = 'Kent D. Lee - Juan Francisco Cardona Mc - Mateo Zabala'
  s.email   = 'mzabala1@eafit.edu.co'
  s.homepage = 'http://www1.eafit.edu.co/fcardona/cursos/st0244/rubycal'
  s.files    = ["lib/token.rb",
                "lib/scanner.rb",
                "lib/ast.rb",
                "lib/parser.rb",
                "lib/calculator.rb",
                "lib/calcex.rb"]
  s.license  = 'ARTISTIC'
  s.executables << 'calc'
end
