#                MathGP Library
#     Copyright (c) 2012 Borislav Stanimirov
#   
#  See the LICENSE.txt file, included in this 
#  distribution for details about the copyright

# gen_swizzle.rb - generates the swizlle inline files

GEN = 'xyzw'
TARGET_PATH = '../mathgp/'

DECL = <<DATA
_internal::swizzle_vectornt<%{dim}, _type, vector%{dim}t<_type>> %{proc}();

vector%{dim}t<_type> %{proc}() const;

DATA

DEF = <<DATA
template <typename _type>
_internal::swizzle_vectornt<%{dim}, _type, vector%{dim}t<_type>> vector%{curdim}t<_type>::%{proc}()
{
    return _internal::swizzle%{dim}(%{calls});
}

template <typename _type>
vector%{dim}t<_type> vector%{curdim}t<_type>::%{proc}() const
{
    return vector%{dim}t<_type>::coord(%{calls});
}

DATA

GEN.length.times do |i|
  cur_gen = GEN[0..i].split(//)
  
  declarations = ''
  definitions = ''
  
  2.upto(GEN.length) do |len|
    cur_gen.repeated_permutation(len) do |perm|
      join = perm.join
      next if GEN[join] # consecutive letters are to be manually (and optimally) defined
      
      calls = perm.join('(), ') + '()'
      
      params = { :curdim => (i+1), :dim => perm.length, :proc => join, :calls => calls }
      
      declarations += DECL % params
      definitions += DEF % params
    end
  end  
  
  File.open(TARGET_PATH + "vector#{i+1}_swizzle_declare.inl", 'w').write(declarations)
  File.open(TARGET_PATH + "vector#{i+1}_swizzle_define.inl", 'w').write(definitions)  
  
end