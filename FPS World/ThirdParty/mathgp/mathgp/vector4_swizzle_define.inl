template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector4t<_type>::xx()
{
    return _internal::swizzle2(x(), x());
}

template <typename _type>
vector2t<_type> vector4t<_type>::xx() const
{
    return vector2t<_type>::coord(x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector4t<_type>::xz()
{
    return _internal::swizzle2(x(), z());
}

template <typename _type>
vector2t<_type> vector4t<_type>::xz() const
{
    return vector2t<_type>::coord(x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector4t<_type>::xw()
{
    return _internal::swizzle2(x(), w());
}

template <typename _type>
vector2t<_type> vector4t<_type>::xw() const
{
    return vector2t<_type>::coord(x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector4t<_type>::yx()
{
    return _internal::swizzle2(y(), x());
}

template <typename _type>
vector2t<_type> vector4t<_type>::yx() const
{
    return vector2t<_type>::coord(y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector4t<_type>::yy()
{
    return _internal::swizzle2(y(), y());
}

template <typename _type>
vector2t<_type> vector4t<_type>::yy() const
{
    return vector2t<_type>::coord(y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector4t<_type>::yw()
{
    return _internal::swizzle2(y(), w());
}

template <typename _type>
vector2t<_type> vector4t<_type>::yw() const
{
    return vector2t<_type>::coord(y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector4t<_type>::zx()
{
    return _internal::swizzle2(z(), x());
}

template <typename _type>
vector2t<_type> vector4t<_type>::zx() const
{
    return vector2t<_type>::coord(z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector4t<_type>::zy()
{
    return _internal::swizzle2(z(), y());
}

template <typename _type>
vector2t<_type> vector4t<_type>::zy() const
{
    return vector2t<_type>::coord(z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector4t<_type>::zz()
{
    return _internal::swizzle2(z(), z());
}

template <typename _type>
vector2t<_type> vector4t<_type>::zz() const
{
    return vector2t<_type>::coord(z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector4t<_type>::wx()
{
    return _internal::swizzle2(w(), x());
}

template <typename _type>
vector2t<_type> vector4t<_type>::wx() const
{
    return vector2t<_type>::coord(w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector4t<_type>::wy()
{
    return _internal::swizzle2(w(), y());
}

template <typename _type>
vector2t<_type> vector4t<_type>::wy() const
{
    return vector2t<_type>::coord(w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector4t<_type>::wz()
{
    return _internal::swizzle2(w(), z());
}

template <typename _type>
vector2t<_type> vector4t<_type>::wz() const
{
    return vector2t<_type>::coord(w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector4t<_type>::ww()
{
    return _internal::swizzle2(w(), w());
}

template <typename _type>
vector2t<_type> vector4t<_type>::ww() const
{
    return vector2t<_type>::coord(w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::xxx()
{
    return _internal::swizzle3(x(), x(), x());
}

template <typename _type>
vector3t<_type> vector4t<_type>::xxx() const
{
    return vector3t<_type>::coord(x(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::xxy()
{
    return _internal::swizzle3(x(), x(), y());
}

template <typename _type>
vector3t<_type> vector4t<_type>::xxy() const
{
    return vector3t<_type>::coord(x(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::xxz()
{
    return _internal::swizzle3(x(), x(), z());
}

template <typename _type>
vector3t<_type> vector4t<_type>::xxz() const
{
    return vector3t<_type>::coord(x(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::xxw()
{
    return _internal::swizzle3(x(), x(), w());
}

template <typename _type>
vector3t<_type> vector4t<_type>::xxw() const
{
    return vector3t<_type>::coord(x(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::xyx()
{
    return _internal::swizzle3(x(), y(), x());
}

template <typename _type>
vector3t<_type> vector4t<_type>::xyx() const
{
    return vector3t<_type>::coord(x(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::xyy()
{
    return _internal::swizzle3(x(), y(), y());
}

template <typename _type>
vector3t<_type> vector4t<_type>::xyy() const
{
    return vector3t<_type>::coord(x(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::xyw()
{
    return _internal::swizzle3(x(), y(), w());
}

template <typename _type>
vector3t<_type> vector4t<_type>::xyw() const
{
    return vector3t<_type>::coord(x(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::xzx()
{
    return _internal::swizzle3(x(), z(), x());
}

template <typename _type>
vector3t<_type> vector4t<_type>::xzx() const
{
    return vector3t<_type>::coord(x(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::xzy()
{
    return _internal::swizzle3(x(), z(), y());
}

template <typename _type>
vector3t<_type> vector4t<_type>::xzy() const
{
    return vector3t<_type>::coord(x(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::xzz()
{
    return _internal::swizzle3(x(), z(), z());
}

template <typename _type>
vector3t<_type> vector4t<_type>::xzz() const
{
    return vector3t<_type>::coord(x(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::xzw()
{
    return _internal::swizzle3(x(), z(), w());
}

template <typename _type>
vector3t<_type> vector4t<_type>::xzw() const
{
    return vector3t<_type>::coord(x(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::xwx()
{
    return _internal::swizzle3(x(), w(), x());
}

template <typename _type>
vector3t<_type> vector4t<_type>::xwx() const
{
    return vector3t<_type>::coord(x(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::xwy()
{
    return _internal::swizzle3(x(), w(), y());
}

template <typename _type>
vector3t<_type> vector4t<_type>::xwy() const
{
    return vector3t<_type>::coord(x(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::xwz()
{
    return _internal::swizzle3(x(), w(), z());
}

template <typename _type>
vector3t<_type> vector4t<_type>::xwz() const
{
    return vector3t<_type>::coord(x(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::xww()
{
    return _internal::swizzle3(x(), w(), w());
}

template <typename _type>
vector3t<_type> vector4t<_type>::xww() const
{
    return vector3t<_type>::coord(x(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::yxx()
{
    return _internal::swizzle3(y(), x(), x());
}

template <typename _type>
vector3t<_type> vector4t<_type>::yxx() const
{
    return vector3t<_type>::coord(y(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::yxy()
{
    return _internal::swizzle3(y(), x(), y());
}

template <typename _type>
vector3t<_type> vector4t<_type>::yxy() const
{
    return vector3t<_type>::coord(y(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::yxz()
{
    return _internal::swizzle3(y(), x(), z());
}

template <typename _type>
vector3t<_type> vector4t<_type>::yxz() const
{
    return vector3t<_type>::coord(y(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::yxw()
{
    return _internal::swizzle3(y(), x(), w());
}

template <typename _type>
vector3t<_type> vector4t<_type>::yxw() const
{
    return vector3t<_type>::coord(y(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::yyx()
{
    return _internal::swizzle3(y(), y(), x());
}

template <typename _type>
vector3t<_type> vector4t<_type>::yyx() const
{
    return vector3t<_type>::coord(y(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::yyy()
{
    return _internal::swizzle3(y(), y(), y());
}

template <typename _type>
vector3t<_type> vector4t<_type>::yyy() const
{
    return vector3t<_type>::coord(y(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::yyz()
{
    return _internal::swizzle3(y(), y(), z());
}

template <typename _type>
vector3t<_type> vector4t<_type>::yyz() const
{
    return vector3t<_type>::coord(y(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::yyw()
{
    return _internal::swizzle3(y(), y(), w());
}

template <typename _type>
vector3t<_type> vector4t<_type>::yyw() const
{
    return vector3t<_type>::coord(y(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::yzx()
{
    return _internal::swizzle3(y(), z(), x());
}

template <typename _type>
vector3t<_type> vector4t<_type>::yzx() const
{
    return vector3t<_type>::coord(y(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::yzy()
{
    return _internal::swizzle3(y(), z(), y());
}

template <typename _type>
vector3t<_type> vector4t<_type>::yzy() const
{
    return vector3t<_type>::coord(y(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::yzz()
{
    return _internal::swizzle3(y(), z(), z());
}

template <typename _type>
vector3t<_type> vector4t<_type>::yzz() const
{
    return vector3t<_type>::coord(y(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::ywx()
{
    return _internal::swizzle3(y(), w(), x());
}

template <typename _type>
vector3t<_type> vector4t<_type>::ywx() const
{
    return vector3t<_type>::coord(y(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::ywy()
{
    return _internal::swizzle3(y(), w(), y());
}

template <typename _type>
vector3t<_type> vector4t<_type>::ywy() const
{
    return vector3t<_type>::coord(y(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::ywz()
{
    return _internal::swizzle3(y(), w(), z());
}

template <typename _type>
vector3t<_type> vector4t<_type>::ywz() const
{
    return vector3t<_type>::coord(y(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::yww()
{
    return _internal::swizzle3(y(), w(), w());
}

template <typename _type>
vector3t<_type> vector4t<_type>::yww() const
{
    return vector3t<_type>::coord(y(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::zxx()
{
    return _internal::swizzle3(z(), x(), x());
}

template <typename _type>
vector3t<_type> vector4t<_type>::zxx() const
{
    return vector3t<_type>::coord(z(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::zxy()
{
    return _internal::swizzle3(z(), x(), y());
}

template <typename _type>
vector3t<_type> vector4t<_type>::zxy() const
{
    return vector3t<_type>::coord(z(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::zxz()
{
    return _internal::swizzle3(z(), x(), z());
}

template <typename _type>
vector3t<_type> vector4t<_type>::zxz() const
{
    return vector3t<_type>::coord(z(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::zxw()
{
    return _internal::swizzle3(z(), x(), w());
}

template <typename _type>
vector3t<_type> vector4t<_type>::zxw() const
{
    return vector3t<_type>::coord(z(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::zyx()
{
    return _internal::swizzle3(z(), y(), x());
}

template <typename _type>
vector3t<_type> vector4t<_type>::zyx() const
{
    return vector3t<_type>::coord(z(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::zyy()
{
    return _internal::swizzle3(z(), y(), y());
}

template <typename _type>
vector3t<_type> vector4t<_type>::zyy() const
{
    return vector3t<_type>::coord(z(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::zyz()
{
    return _internal::swizzle3(z(), y(), z());
}

template <typename _type>
vector3t<_type> vector4t<_type>::zyz() const
{
    return vector3t<_type>::coord(z(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::zyw()
{
    return _internal::swizzle3(z(), y(), w());
}

template <typename _type>
vector3t<_type> vector4t<_type>::zyw() const
{
    return vector3t<_type>::coord(z(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::zzx()
{
    return _internal::swizzle3(z(), z(), x());
}

template <typename _type>
vector3t<_type> vector4t<_type>::zzx() const
{
    return vector3t<_type>::coord(z(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::zzy()
{
    return _internal::swizzle3(z(), z(), y());
}

template <typename _type>
vector3t<_type> vector4t<_type>::zzy() const
{
    return vector3t<_type>::coord(z(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::zzz()
{
    return _internal::swizzle3(z(), z(), z());
}

template <typename _type>
vector3t<_type> vector4t<_type>::zzz() const
{
    return vector3t<_type>::coord(z(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::zzw()
{
    return _internal::swizzle3(z(), z(), w());
}

template <typename _type>
vector3t<_type> vector4t<_type>::zzw() const
{
    return vector3t<_type>::coord(z(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::zwx()
{
    return _internal::swizzle3(z(), w(), x());
}

template <typename _type>
vector3t<_type> vector4t<_type>::zwx() const
{
    return vector3t<_type>::coord(z(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::zwy()
{
    return _internal::swizzle3(z(), w(), y());
}

template <typename _type>
vector3t<_type> vector4t<_type>::zwy() const
{
    return vector3t<_type>::coord(z(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::zwz()
{
    return _internal::swizzle3(z(), w(), z());
}

template <typename _type>
vector3t<_type> vector4t<_type>::zwz() const
{
    return vector3t<_type>::coord(z(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::zww()
{
    return _internal::swizzle3(z(), w(), w());
}

template <typename _type>
vector3t<_type> vector4t<_type>::zww() const
{
    return vector3t<_type>::coord(z(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::wxx()
{
    return _internal::swizzle3(w(), x(), x());
}

template <typename _type>
vector3t<_type> vector4t<_type>::wxx() const
{
    return vector3t<_type>::coord(w(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::wxy()
{
    return _internal::swizzle3(w(), x(), y());
}

template <typename _type>
vector3t<_type> vector4t<_type>::wxy() const
{
    return vector3t<_type>::coord(w(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::wxz()
{
    return _internal::swizzle3(w(), x(), z());
}

template <typename _type>
vector3t<_type> vector4t<_type>::wxz() const
{
    return vector3t<_type>::coord(w(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::wxw()
{
    return _internal::swizzle3(w(), x(), w());
}

template <typename _type>
vector3t<_type> vector4t<_type>::wxw() const
{
    return vector3t<_type>::coord(w(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::wyx()
{
    return _internal::swizzle3(w(), y(), x());
}

template <typename _type>
vector3t<_type> vector4t<_type>::wyx() const
{
    return vector3t<_type>::coord(w(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::wyy()
{
    return _internal::swizzle3(w(), y(), y());
}

template <typename _type>
vector3t<_type> vector4t<_type>::wyy() const
{
    return vector3t<_type>::coord(w(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::wyz()
{
    return _internal::swizzle3(w(), y(), z());
}

template <typename _type>
vector3t<_type> vector4t<_type>::wyz() const
{
    return vector3t<_type>::coord(w(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::wyw()
{
    return _internal::swizzle3(w(), y(), w());
}

template <typename _type>
vector3t<_type> vector4t<_type>::wyw() const
{
    return vector3t<_type>::coord(w(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::wzx()
{
    return _internal::swizzle3(w(), z(), x());
}

template <typename _type>
vector3t<_type> vector4t<_type>::wzx() const
{
    return vector3t<_type>::coord(w(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::wzy()
{
    return _internal::swizzle3(w(), z(), y());
}

template <typename _type>
vector3t<_type> vector4t<_type>::wzy() const
{
    return vector3t<_type>::coord(w(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::wzz()
{
    return _internal::swizzle3(w(), z(), z());
}

template <typename _type>
vector3t<_type> vector4t<_type>::wzz() const
{
    return vector3t<_type>::coord(w(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::wzw()
{
    return _internal::swizzle3(w(), z(), w());
}

template <typename _type>
vector3t<_type> vector4t<_type>::wzw() const
{
    return vector3t<_type>::coord(w(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::wwx()
{
    return _internal::swizzle3(w(), w(), x());
}

template <typename _type>
vector3t<_type> vector4t<_type>::wwx() const
{
    return vector3t<_type>::coord(w(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::wwy()
{
    return _internal::swizzle3(w(), w(), y());
}

template <typename _type>
vector3t<_type> vector4t<_type>::wwy() const
{
    return vector3t<_type>::coord(w(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::wwz()
{
    return _internal::swizzle3(w(), w(), z());
}

template <typename _type>
vector3t<_type> vector4t<_type>::wwz() const
{
    return vector3t<_type>::coord(w(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector4t<_type>::www()
{
    return _internal::swizzle3(w(), w(), w());
}

template <typename _type>
vector3t<_type> vector4t<_type>::www() const
{
    return vector3t<_type>::coord(w(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xxxx()
{
    return _internal::swizzle4(x(), x(), x(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xxxx() const
{
    return vector4t<_type>::coord(x(), x(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xxxy()
{
    return _internal::swizzle4(x(), x(), x(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xxxy() const
{
    return vector4t<_type>::coord(x(), x(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xxxz()
{
    return _internal::swizzle4(x(), x(), x(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xxxz() const
{
    return vector4t<_type>::coord(x(), x(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xxxw()
{
    return _internal::swizzle4(x(), x(), x(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xxxw() const
{
    return vector4t<_type>::coord(x(), x(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xxyx()
{
    return _internal::swizzle4(x(), x(), y(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xxyx() const
{
    return vector4t<_type>::coord(x(), x(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xxyy()
{
    return _internal::swizzle4(x(), x(), y(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xxyy() const
{
    return vector4t<_type>::coord(x(), x(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xxyz()
{
    return _internal::swizzle4(x(), x(), y(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xxyz() const
{
    return vector4t<_type>::coord(x(), x(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xxyw()
{
    return _internal::swizzle4(x(), x(), y(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xxyw() const
{
    return vector4t<_type>::coord(x(), x(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xxzx()
{
    return _internal::swizzle4(x(), x(), z(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xxzx() const
{
    return vector4t<_type>::coord(x(), x(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xxzy()
{
    return _internal::swizzle4(x(), x(), z(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xxzy() const
{
    return vector4t<_type>::coord(x(), x(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xxzz()
{
    return _internal::swizzle4(x(), x(), z(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xxzz() const
{
    return vector4t<_type>::coord(x(), x(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xxzw()
{
    return _internal::swizzle4(x(), x(), z(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xxzw() const
{
    return vector4t<_type>::coord(x(), x(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xxwx()
{
    return _internal::swizzle4(x(), x(), w(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xxwx() const
{
    return vector4t<_type>::coord(x(), x(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xxwy()
{
    return _internal::swizzle4(x(), x(), w(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xxwy() const
{
    return vector4t<_type>::coord(x(), x(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xxwz()
{
    return _internal::swizzle4(x(), x(), w(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xxwz() const
{
    return vector4t<_type>::coord(x(), x(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xxww()
{
    return _internal::swizzle4(x(), x(), w(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xxww() const
{
    return vector4t<_type>::coord(x(), x(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xyxx()
{
    return _internal::swizzle4(x(), y(), x(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xyxx() const
{
    return vector4t<_type>::coord(x(), y(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xyxy()
{
    return _internal::swizzle4(x(), y(), x(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xyxy() const
{
    return vector4t<_type>::coord(x(), y(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xyxz()
{
    return _internal::swizzle4(x(), y(), x(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xyxz() const
{
    return vector4t<_type>::coord(x(), y(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xyxw()
{
    return _internal::swizzle4(x(), y(), x(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xyxw() const
{
    return vector4t<_type>::coord(x(), y(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xyyx()
{
    return _internal::swizzle4(x(), y(), y(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xyyx() const
{
    return vector4t<_type>::coord(x(), y(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xyyy()
{
    return _internal::swizzle4(x(), y(), y(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xyyy() const
{
    return vector4t<_type>::coord(x(), y(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xyyz()
{
    return _internal::swizzle4(x(), y(), y(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xyyz() const
{
    return vector4t<_type>::coord(x(), y(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xyyw()
{
    return _internal::swizzle4(x(), y(), y(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xyyw() const
{
    return vector4t<_type>::coord(x(), y(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xyzx()
{
    return _internal::swizzle4(x(), y(), z(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xyzx() const
{
    return vector4t<_type>::coord(x(), y(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xyzy()
{
    return _internal::swizzle4(x(), y(), z(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xyzy() const
{
    return vector4t<_type>::coord(x(), y(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xyzz()
{
    return _internal::swizzle4(x(), y(), z(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xyzz() const
{
    return vector4t<_type>::coord(x(), y(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xywx()
{
    return _internal::swizzle4(x(), y(), w(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xywx() const
{
    return vector4t<_type>::coord(x(), y(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xywy()
{
    return _internal::swizzle4(x(), y(), w(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xywy() const
{
    return vector4t<_type>::coord(x(), y(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xywz()
{
    return _internal::swizzle4(x(), y(), w(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xywz() const
{
    return vector4t<_type>::coord(x(), y(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xyww()
{
    return _internal::swizzle4(x(), y(), w(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xyww() const
{
    return vector4t<_type>::coord(x(), y(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xzxx()
{
    return _internal::swizzle4(x(), z(), x(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xzxx() const
{
    return vector4t<_type>::coord(x(), z(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xzxy()
{
    return _internal::swizzle4(x(), z(), x(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xzxy() const
{
    return vector4t<_type>::coord(x(), z(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xzxz()
{
    return _internal::swizzle4(x(), z(), x(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xzxz() const
{
    return vector4t<_type>::coord(x(), z(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xzxw()
{
    return _internal::swizzle4(x(), z(), x(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xzxw() const
{
    return vector4t<_type>::coord(x(), z(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xzyx()
{
    return _internal::swizzle4(x(), z(), y(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xzyx() const
{
    return vector4t<_type>::coord(x(), z(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xzyy()
{
    return _internal::swizzle4(x(), z(), y(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xzyy() const
{
    return vector4t<_type>::coord(x(), z(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xzyz()
{
    return _internal::swizzle4(x(), z(), y(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xzyz() const
{
    return vector4t<_type>::coord(x(), z(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xzyw()
{
    return _internal::swizzle4(x(), z(), y(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xzyw() const
{
    return vector4t<_type>::coord(x(), z(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xzzx()
{
    return _internal::swizzle4(x(), z(), z(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xzzx() const
{
    return vector4t<_type>::coord(x(), z(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xzzy()
{
    return _internal::swizzle4(x(), z(), z(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xzzy() const
{
    return vector4t<_type>::coord(x(), z(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xzzz()
{
    return _internal::swizzle4(x(), z(), z(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xzzz() const
{
    return vector4t<_type>::coord(x(), z(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xzzw()
{
    return _internal::swizzle4(x(), z(), z(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xzzw() const
{
    return vector4t<_type>::coord(x(), z(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xzwx()
{
    return _internal::swizzle4(x(), z(), w(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xzwx() const
{
    return vector4t<_type>::coord(x(), z(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xzwy()
{
    return _internal::swizzle4(x(), z(), w(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xzwy() const
{
    return vector4t<_type>::coord(x(), z(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xzwz()
{
    return _internal::swizzle4(x(), z(), w(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xzwz() const
{
    return vector4t<_type>::coord(x(), z(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xzww()
{
    return _internal::swizzle4(x(), z(), w(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xzww() const
{
    return vector4t<_type>::coord(x(), z(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xwxx()
{
    return _internal::swizzle4(x(), w(), x(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xwxx() const
{
    return vector4t<_type>::coord(x(), w(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xwxy()
{
    return _internal::swizzle4(x(), w(), x(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xwxy() const
{
    return vector4t<_type>::coord(x(), w(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xwxz()
{
    return _internal::swizzle4(x(), w(), x(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xwxz() const
{
    return vector4t<_type>::coord(x(), w(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xwxw()
{
    return _internal::swizzle4(x(), w(), x(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xwxw() const
{
    return vector4t<_type>::coord(x(), w(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xwyx()
{
    return _internal::swizzle4(x(), w(), y(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xwyx() const
{
    return vector4t<_type>::coord(x(), w(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xwyy()
{
    return _internal::swizzle4(x(), w(), y(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xwyy() const
{
    return vector4t<_type>::coord(x(), w(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xwyz()
{
    return _internal::swizzle4(x(), w(), y(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xwyz() const
{
    return vector4t<_type>::coord(x(), w(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xwyw()
{
    return _internal::swizzle4(x(), w(), y(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xwyw() const
{
    return vector4t<_type>::coord(x(), w(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xwzx()
{
    return _internal::swizzle4(x(), w(), z(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xwzx() const
{
    return vector4t<_type>::coord(x(), w(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xwzy()
{
    return _internal::swizzle4(x(), w(), z(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xwzy() const
{
    return vector4t<_type>::coord(x(), w(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xwzz()
{
    return _internal::swizzle4(x(), w(), z(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xwzz() const
{
    return vector4t<_type>::coord(x(), w(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xwzw()
{
    return _internal::swizzle4(x(), w(), z(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xwzw() const
{
    return vector4t<_type>::coord(x(), w(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xwwx()
{
    return _internal::swizzle4(x(), w(), w(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xwwx() const
{
    return vector4t<_type>::coord(x(), w(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xwwy()
{
    return _internal::swizzle4(x(), w(), w(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xwwy() const
{
    return vector4t<_type>::coord(x(), w(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xwwz()
{
    return _internal::swizzle4(x(), w(), w(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xwwz() const
{
    return vector4t<_type>::coord(x(), w(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::xwww()
{
    return _internal::swizzle4(x(), w(), w(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::xwww() const
{
    return vector4t<_type>::coord(x(), w(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yxxx()
{
    return _internal::swizzle4(y(), x(), x(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yxxx() const
{
    return vector4t<_type>::coord(y(), x(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yxxy()
{
    return _internal::swizzle4(y(), x(), x(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yxxy() const
{
    return vector4t<_type>::coord(y(), x(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yxxz()
{
    return _internal::swizzle4(y(), x(), x(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yxxz() const
{
    return vector4t<_type>::coord(y(), x(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yxxw()
{
    return _internal::swizzle4(y(), x(), x(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yxxw() const
{
    return vector4t<_type>::coord(y(), x(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yxyx()
{
    return _internal::swizzle4(y(), x(), y(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yxyx() const
{
    return vector4t<_type>::coord(y(), x(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yxyy()
{
    return _internal::swizzle4(y(), x(), y(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yxyy() const
{
    return vector4t<_type>::coord(y(), x(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yxyz()
{
    return _internal::swizzle4(y(), x(), y(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yxyz() const
{
    return vector4t<_type>::coord(y(), x(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yxyw()
{
    return _internal::swizzle4(y(), x(), y(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yxyw() const
{
    return vector4t<_type>::coord(y(), x(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yxzx()
{
    return _internal::swizzle4(y(), x(), z(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yxzx() const
{
    return vector4t<_type>::coord(y(), x(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yxzy()
{
    return _internal::swizzle4(y(), x(), z(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yxzy() const
{
    return vector4t<_type>::coord(y(), x(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yxzz()
{
    return _internal::swizzle4(y(), x(), z(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yxzz() const
{
    return vector4t<_type>::coord(y(), x(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yxzw()
{
    return _internal::swizzle4(y(), x(), z(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yxzw() const
{
    return vector4t<_type>::coord(y(), x(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yxwx()
{
    return _internal::swizzle4(y(), x(), w(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yxwx() const
{
    return vector4t<_type>::coord(y(), x(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yxwy()
{
    return _internal::swizzle4(y(), x(), w(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yxwy() const
{
    return vector4t<_type>::coord(y(), x(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yxwz()
{
    return _internal::swizzle4(y(), x(), w(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yxwz() const
{
    return vector4t<_type>::coord(y(), x(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yxww()
{
    return _internal::swizzle4(y(), x(), w(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yxww() const
{
    return vector4t<_type>::coord(y(), x(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yyxx()
{
    return _internal::swizzle4(y(), y(), x(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yyxx() const
{
    return vector4t<_type>::coord(y(), y(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yyxy()
{
    return _internal::swizzle4(y(), y(), x(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yyxy() const
{
    return vector4t<_type>::coord(y(), y(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yyxz()
{
    return _internal::swizzle4(y(), y(), x(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yyxz() const
{
    return vector4t<_type>::coord(y(), y(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yyxw()
{
    return _internal::swizzle4(y(), y(), x(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yyxw() const
{
    return vector4t<_type>::coord(y(), y(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yyyx()
{
    return _internal::swizzle4(y(), y(), y(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yyyx() const
{
    return vector4t<_type>::coord(y(), y(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yyyy()
{
    return _internal::swizzle4(y(), y(), y(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yyyy() const
{
    return vector4t<_type>::coord(y(), y(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yyyz()
{
    return _internal::swizzle4(y(), y(), y(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yyyz() const
{
    return vector4t<_type>::coord(y(), y(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yyyw()
{
    return _internal::swizzle4(y(), y(), y(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yyyw() const
{
    return vector4t<_type>::coord(y(), y(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yyzx()
{
    return _internal::swizzle4(y(), y(), z(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yyzx() const
{
    return vector4t<_type>::coord(y(), y(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yyzy()
{
    return _internal::swizzle4(y(), y(), z(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yyzy() const
{
    return vector4t<_type>::coord(y(), y(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yyzz()
{
    return _internal::swizzle4(y(), y(), z(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yyzz() const
{
    return vector4t<_type>::coord(y(), y(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yyzw()
{
    return _internal::swizzle4(y(), y(), z(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yyzw() const
{
    return vector4t<_type>::coord(y(), y(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yywx()
{
    return _internal::swizzle4(y(), y(), w(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yywx() const
{
    return vector4t<_type>::coord(y(), y(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yywy()
{
    return _internal::swizzle4(y(), y(), w(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yywy() const
{
    return vector4t<_type>::coord(y(), y(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yywz()
{
    return _internal::swizzle4(y(), y(), w(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yywz() const
{
    return vector4t<_type>::coord(y(), y(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yyww()
{
    return _internal::swizzle4(y(), y(), w(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yyww() const
{
    return vector4t<_type>::coord(y(), y(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yzxx()
{
    return _internal::swizzle4(y(), z(), x(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yzxx() const
{
    return vector4t<_type>::coord(y(), z(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yzxy()
{
    return _internal::swizzle4(y(), z(), x(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yzxy() const
{
    return vector4t<_type>::coord(y(), z(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yzxz()
{
    return _internal::swizzle4(y(), z(), x(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yzxz() const
{
    return vector4t<_type>::coord(y(), z(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yzxw()
{
    return _internal::swizzle4(y(), z(), x(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yzxw() const
{
    return vector4t<_type>::coord(y(), z(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yzyx()
{
    return _internal::swizzle4(y(), z(), y(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yzyx() const
{
    return vector4t<_type>::coord(y(), z(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yzyy()
{
    return _internal::swizzle4(y(), z(), y(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yzyy() const
{
    return vector4t<_type>::coord(y(), z(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yzyz()
{
    return _internal::swizzle4(y(), z(), y(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yzyz() const
{
    return vector4t<_type>::coord(y(), z(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yzyw()
{
    return _internal::swizzle4(y(), z(), y(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yzyw() const
{
    return vector4t<_type>::coord(y(), z(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yzzx()
{
    return _internal::swizzle4(y(), z(), z(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yzzx() const
{
    return vector4t<_type>::coord(y(), z(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yzzy()
{
    return _internal::swizzle4(y(), z(), z(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yzzy() const
{
    return vector4t<_type>::coord(y(), z(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yzzz()
{
    return _internal::swizzle4(y(), z(), z(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yzzz() const
{
    return vector4t<_type>::coord(y(), z(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yzzw()
{
    return _internal::swizzle4(y(), z(), z(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yzzw() const
{
    return vector4t<_type>::coord(y(), z(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yzwx()
{
    return _internal::swizzle4(y(), z(), w(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yzwx() const
{
    return vector4t<_type>::coord(y(), z(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yzwy()
{
    return _internal::swizzle4(y(), z(), w(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yzwy() const
{
    return vector4t<_type>::coord(y(), z(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yzwz()
{
    return _internal::swizzle4(y(), z(), w(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yzwz() const
{
    return vector4t<_type>::coord(y(), z(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::yzww()
{
    return _internal::swizzle4(y(), z(), w(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::yzww() const
{
    return vector4t<_type>::coord(y(), z(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::ywxx()
{
    return _internal::swizzle4(y(), w(), x(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::ywxx() const
{
    return vector4t<_type>::coord(y(), w(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::ywxy()
{
    return _internal::swizzle4(y(), w(), x(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::ywxy() const
{
    return vector4t<_type>::coord(y(), w(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::ywxz()
{
    return _internal::swizzle4(y(), w(), x(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::ywxz() const
{
    return vector4t<_type>::coord(y(), w(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::ywxw()
{
    return _internal::swizzle4(y(), w(), x(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::ywxw() const
{
    return vector4t<_type>::coord(y(), w(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::ywyx()
{
    return _internal::swizzle4(y(), w(), y(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::ywyx() const
{
    return vector4t<_type>::coord(y(), w(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::ywyy()
{
    return _internal::swizzle4(y(), w(), y(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::ywyy() const
{
    return vector4t<_type>::coord(y(), w(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::ywyz()
{
    return _internal::swizzle4(y(), w(), y(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::ywyz() const
{
    return vector4t<_type>::coord(y(), w(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::ywyw()
{
    return _internal::swizzle4(y(), w(), y(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::ywyw() const
{
    return vector4t<_type>::coord(y(), w(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::ywzx()
{
    return _internal::swizzle4(y(), w(), z(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::ywzx() const
{
    return vector4t<_type>::coord(y(), w(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::ywzy()
{
    return _internal::swizzle4(y(), w(), z(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::ywzy() const
{
    return vector4t<_type>::coord(y(), w(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::ywzz()
{
    return _internal::swizzle4(y(), w(), z(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::ywzz() const
{
    return vector4t<_type>::coord(y(), w(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::ywzw()
{
    return _internal::swizzle4(y(), w(), z(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::ywzw() const
{
    return vector4t<_type>::coord(y(), w(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::ywwx()
{
    return _internal::swizzle4(y(), w(), w(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::ywwx() const
{
    return vector4t<_type>::coord(y(), w(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::ywwy()
{
    return _internal::swizzle4(y(), w(), w(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::ywwy() const
{
    return vector4t<_type>::coord(y(), w(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::ywwz()
{
    return _internal::swizzle4(y(), w(), w(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::ywwz() const
{
    return vector4t<_type>::coord(y(), w(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::ywww()
{
    return _internal::swizzle4(y(), w(), w(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::ywww() const
{
    return vector4t<_type>::coord(y(), w(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zxxx()
{
    return _internal::swizzle4(z(), x(), x(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zxxx() const
{
    return vector4t<_type>::coord(z(), x(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zxxy()
{
    return _internal::swizzle4(z(), x(), x(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zxxy() const
{
    return vector4t<_type>::coord(z(), x(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zxxz()
{
    return _internal::swizzle4(z(), x(), x(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zxxz() const
{
    return vector4t<_type>::coord(z(), x(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zxxw()
{
    return _internal::swizzle4(z(), x(), x(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zxxw() const
{
    return vector4t<_type>::coord(z(), x(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zxyx()
{
    return _internal::swizzle4(z(), x(), y(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zxyx() const
{
    return vector4t<_type>::coord(z(), x(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zxyy()
{
    return _internal::swizzle4(z(), x(), y(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zxyy() const
{
    return vector4t<_type>::coord(z(), x(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zxyz()
{
    return _internal::swizzle4(z(), x(), y(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zxyz() const
{
    return vector4t<_type>::coord(z(), x(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zxyw()
{
    return _internal::swizzle4(z(), x(), y(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zxyw() const
{
    return vector4t<_type>::coord(z(), x(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zxzx()
{
    return _internal::swizzle4(z(), x(), z(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zxzx() const
{
    return vector4t<_type>::coord(z(), x(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zxzy()
{
    return _internal::swizzle4(z(), x(), z(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zxzy() const
{
    return vector4t<_type>::coord(z(), x(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zxzz()
{
    return _internal::swizzle4(z(), x(), z(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zxzz() const
{
    return vector4t<_type>::coord(z(), x(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zxzw()
{
    return _internal::swizzle4(z(), x(), z(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zxzw() const
{
    return vector4t<_type>::coord(z(), x(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zxwx()
{
    return _internal::swizzle4(z(), x(), w(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zxwx() const
{
    return vector4t<_type>::coord(z(), x(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zxwy()
{
    return _internal::swizzle4(z(), x(), w(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zxwy() const
{
    return vector4t<_type>::coord(z(), x(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zxwz()
{
    return _internal::swizzle4(z(), x(), w(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zxwz() const
{
    return vector4t<_type>::coord(z(), x(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zxww()
{
    return _internal::swizzle4(z(), x(), w(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zxww() const
{
    return vector4t<_type>::coord(z(), x(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zyxx()
{
    return _internal::swizzle4(z(), y(), x(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zyxx() const
{
    return vector4t<_type>::coord(z(), y(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zyxy()
{
    return _internal::swizzle4(z(), y(), x(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zyxy() const
{
    return vector4t<_type>::coord(z(), y(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zyxz()
{
    return _internal::swizzle4(z(), y(), x(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zyxz() const
{
    return vector4t<_type>::coord(z(), y(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zyxw()
{
    return _internal::swizzle4(z(), y(), x(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zyxw() const
{
    return vector4t<_type>::coord(z(), y(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zyyx()
{
    return _internal::swizzle4(z(), y(), y(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zyyx() const
{
    return vector4t<_type>::coord(z(), y(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zyyy()
{
    return _internal::swizzle4(z(), y(), y(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zyyy() const
{
    return vector4t<_type>::coord(z(), y(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zyyz()
{
    return _internal::swizzle4(z(), y(), y(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zyyz() const
{
    return vector4t<_type>::coord(z(), y(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zyyw()
{
    return _internal::swizzle4(z(), y(), y(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zyyw() const
{
    return vector4t<_type>::coord(z(), y(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zyzx()
{
    return _internal::swizzle4(z(), y(), z(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zyzx() const
{
    return vector4t<_type>::coord(z(), y(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zyzy()
{
    return _internal::swizzle4(z(), y(), z(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zyzy() const
{
    return vector4t<_type>::coord(z(), y(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zyzz()
{
    return _internal::swizzle4(z(), y(), z(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zyzz() const
{
    return vector4t<_type>::coord(z(), y(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zyzw()
{
    return _internal::swizzle4(z(), y(), z(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zyzw() const
{
    return vector4t<_type>::coord(z(), y(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zywx()
{
    return _internal::swizzle4(z(), y(), w(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zywx() const
{
    return vector4t<_type>::coord(z(), y(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zywy()
{
    return _internal::swizzle4(z(), y(), w(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zywy() const
{
    return vector4t<_type>::coord(z(), y(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zywz()
{
    return _internal::swizzle4(z(), y(), w(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zywz() const
{
    return vector4t<_type>::coord(z(), y(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zyww()
{
    return _internal::swizzle4(z(), y(), w(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zyww() const
{
    return vector4t<_type>::coord(z(), y(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zzxx()
{
    return _internal::swizzle4(z(), z(), x(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zzxx() const
{
    return vector4t<_type>::coord(z(), z(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zzxy()
{
    return _internal::swizzle4(z(), z(), x(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zzxy() const
{
    return vector4t<_type>::coord(z(), z(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zzxz()
{
    return _internal::swizzle4(z(), z(), x(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zzxz() const
{
    return vector4t<_type>::coord(z(), z(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zzxw()
{
    return _internal::swizzle4(z(), z(), x(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zzxw() const
{
    return vector4t<_type>::coord(z(), z(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zzyx()
{
    return _internal::swizzle4(z(), z(), y(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zzyx() const
{
    return vector4t<_type>::coord(z(), z(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zzyy()
{
    return _internal::swizzle4(z(), z(), y(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zzyy() const
{
    return vector4t<_type>::coord(z(), z(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zzyz()
{
    return _internal::swizzle4(z(), z(), y(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zzyz() const
{
    return vector4t<_type>::coord(z(), z(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zzyw()
{
    return _internal::swizzle4(z(), z(), y(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zzyw() const
{
    return vector4t<_type>::coord(z(), z(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zzzx()
{
    return _internal::swizzle4(z(), z(), z(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zzzx() const
{
    return vector4t<_type>::coord(z(), z(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zzzy()
{
    return _internal::swizzle4(z(), z(), z(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zzzy() const
{
    return vector4t<_type>::coord(z(), z(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zzzz()
{
    return _internal::swizzle4(z(), z(), z(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zzzz() const
{
    return vector4t<_type>::coord(z(), z(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zzzw()
{
    return _internal::swizzle4(z(), z(), z(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zzzw() const
{
    return vector4t<_type>::coord(z(), z(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zzwx()
{
    return _internal::swizzle4(z(), z(), w(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zzwx() const
{
    return vector4t<_type>::coord(z(), z(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zzwy()
{
    return _internal::swizzle4(z(), z(), w(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zzwy() const
{
    return vector4t<_type>::coord(z(), z(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zzwz()
{
    return _internal::swizzle4(z(), z(), w(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zzwz() const
{
    return vector4t<_type>::coord(z(), z(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zzww()
{
    return _internal::swizzle4(z(), z(), w(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zzww() const
{
    return vector4t<_type>::coord(z(), z(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zwxx()
{
    return _internal::swizzle4(z(), w(), x(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zwxx() const
{
    return vector4t<_type>::coord(z(), w(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zwxy()
{
    return _internal::swizzle4(z(), w(), x(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zwxy() const
{
    return vector4t<_type>::coord(z(), w(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zwxz()
{
    return _internal::swizzle4(z(), w(), x(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zwxz() const
{
    return vector4t<_type>::coord(z(), w(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zwxw()
{
    return _internal::swizzle4(z(), w(), x(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zwxw() const
{
    return vector4t<_type>::coord(z(), w(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zwyx()
{
    return _internal::swizzle4(z(), w(), y(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zwyx() const
{
    return vector4t<_type>::coord(z(), w(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zwyy()
{
    return _internal::swizzle4(z(), w(), y(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zwyy() const
{
    return vector4t<_type>::coord(z(), w(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zwyz()
{
    return _internal::swizzle4(z(), w(), y(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zwyz() const
{
    return vector4t<_type>::coord(z(), w(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zwyw()
{
    return _internal::swizzle4(z(), w(), y(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zwyw() const
{
    return vector4t<_type>::coord(z(), w(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zwzx()
{
    return _internal::swizzle4(z(), w(), z(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zwzx() const
{
    return vector4t<_type>::coord(z(), w(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zwzy()
{
    return _internal::swizzle4(z(), w(), z(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zwzy() const
{
    return vector4t<_type>::coord(z(), w(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zwzz()
{
    return _internal::swizzle4(z(), w(), z(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zwzz() const
{
    return vector4t<_type>::coord(z(), w(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zwzw()
{
    return _internal::swizzle4(z(), w(), z(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zwzw() const
{
    return vector4t<_type>::coord(z(), w(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zwwx()
{
    return _internal::swizzle4(z(), w(), w(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zwwx() const
{
    return vector4t<_type>::coord(z(), w(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zwwy()
{
    return _internal::swizzle4(z(), w(), w(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zwwy() const
{
    return vector4t<_type>::coord(z(), w(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zwwz()
{
    return _internal::swizzle4(z(), w(), w(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zwwz() const
{
    return vector4t<_type>::coord(z(), w(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::zwww()
{
    return _internal::swizzle4(z(), w(), w(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::zwww() const
{
    return vector4t<_type>::coord(z(), w(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wxxx()
{
    return _internal::swizzle4(w(), x(), x(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wxxx() const
{
    return vector4t<_type>::coord(w(), x(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wxxy()
{
    return _internal::swizzle4(w(), x(), x(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wxxy() const
{
    return vector4t<_type>::coord(w(), x(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wxxz()
{
    return _internal::swizzle4(w(), x(), x(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wxxz() const
{
    return vector4t<_type>::coord(w(), x(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wxxw()
{
    return _internal::swizzle4(w(), x(), x(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wxxw() const
{
    return vector4t<_type>::coord(w(), x(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wxyx()
{
    return _internal::swizzle4(w(), x(), y(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wxyx() const
{
    return vector4t<_type>::coord(w(), x(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wxyy()
{
    return _internal::swizzle4(w(), x(), y(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wxyy() const
{
    return vector4t<_type>::coord(w(), x(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wxyz()
{
    return _internal::swizzle4(w(), x(), y(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wxyz() const
{
    return vector4t<_type>::coord(w(), x(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wxyw()
{
    return _internal::swizzle4(w(), x(), y(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wxyw() const
{
    return vector4t<_type>::coord(w(), x(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wxzx()
{
    return _internal::swizzle4(w(), x(), z(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wxzx() const
{
    return vector4t<_type>::coord(w(), x(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wxzy()
{
    return _internal::swizzle4(w(), x(), z(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wxzy() const
{
    return vector4t<_type>::coord(w(), x(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wxzz()
{
    return _internal::swizzle4(w(), x(), z(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wxzz() const
{
    return vector4t<_type>::coord(w(), x(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wxzw()
{
    return _internal::swizzle4(w(), x(), z(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wxzw() const
{
    return vector4t<_type>::coord(w(), x(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wxwx()
{
    return _internal::swizzle4(w(), x(), w(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wxwx() const
{
    return vector4t<_type>::coord(w(), x(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wxwy()
{
    return _internal::swizzle4(w(), x(), w(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wxwy() const
{
    return vector4t<_type>::coord(w(), x(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wxwz()
{
    return _internal::swizzle4(w(), x(), w(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wxwz() const
{
    return vector4t<_type>::coord(w(), x(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wxww()
{
    return _internal::swizzle4(w(), x(), w(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wxww() const
{
    return vector4t<_type>::coord(w(), x(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wyxx()
{
    return _internal::swizzle4(w(), y(), x(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wyxx() const
{
    return vector4t<_type>::coord(w(), y(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wyxy()
{
    return _internal::swizzle4(w(), y(), x(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wyxy() const
{
    return vector4t<_type>::coord(w(), y(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wyxz()
{
    return _internal::swizzle4(w(), y(), x(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wyxz() const
{
    return vector4t<_type>::coord(w(), y(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wyxw()
{
    return _internal::swizzle4(w(), y(), x(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wyxw() const
{
    return vector4t<_type>::coord(w(), y(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wyyx()
{
    return _internal::swizzle4(w(), y(), y(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wyyx() const
{
    return vector4t<_type>::coord(w(), y(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wyyy()
{
    return _internal::swizzle4(w(), y(), y(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wyyy() const
{
    return vector4t<_type>::coord(w(), y(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wyyz()
{
    return _internal::swizzle4(w(), y(), y(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wyyz() const
{
    return vector4t<_type>::coord(w(), y(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wyyw()
{
    return _internal::swizzle4(w(), y(), y(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wyyw() const
{
    return vector4t<_type>::coord(w(), y(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wyzx()
{
    return _internal::swizzle4(w(), y(), z(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wyzx() const
{
    return vector4t<_type>::coord(w(), y(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wyzy()
{
    return _internal::swizzle4(w(), y(), z(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wyzy() const
{
    return vector4t<_type>::coord(w(), y(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wyzz()
{
    return _internal::swizzle4(w(), y(), z(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wyzz() const
{
    return vector4t<_type>::coord(w(), y(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wyzw()
{
    return _internal::swizzle4(w(), y(), z(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wyzw() const
{
    return vector4t<_type>::coord(w(), y(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wywx()
{
    return _internal::swizzle4(w(), y(), w(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wywx() const
{
    return vector4t<_type>::coord(w(), y(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wywy()
{
    return _internal::swizzle4(w(), y(), w(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wywy() const
{
    return vector4t<_type>::coord(w(), y(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wywz()
{
    return _internal::swizzle4(w(), y(), w(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wywz() const
{
    return vector4t<_type>::coord(w(), y(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wyww()
{
    return _internal::swizzle4(w(), y(), w(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wyww() const
{
    return vector4t<_type>::coord(w(), y(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wzxx()
{
    return _internal::swizzle4(w(), z(), x(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wzxx() const
{
    return vector4t<_type>::coord(w(), z(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wzxy()
{
    return _internal::swizzle4(w(), z(), x(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wzxy() const
{
    return vector4t<_type>::coord(w(), z(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wzxz()
{
    return _internal::swizzle4(w(), z(), x(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wzxz() const
{
    return vector4t<_type>::coord(w(), z(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wzxw()
{
    return _internal::swizzle4(w(), z(), x(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wzxw() const
{
    return vector4t<_type>::coord(w(), z(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wzyx()
{
    return _internal::swizzle4(w(), z(), y(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wzyx() const
{
    return vector4t<_type>::coord(w(), z(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wzyy()
{
    return _internal::swizzle4(w(), z(), y(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wzyy() const
{
    return vector4t<_type>::coord(w(), z(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wzyz()
{
    return _internal::swizzle4(w(), z(), y(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wzyz() const
{
    return vector4t<_type>::coord(w(), z(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wzyw()
{
    return _internal::swizzle4(w(), z(), y(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wzyw() const
{
    return vector4t<_type>::coord(w(), z(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wzzx()
{
    return _internal::swizzle4(w(), z(), z(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wzzx() const
{
    return vector4t<_type>::coord(w(), z(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wzzy()
{
    return _internal::swizzle4(w(), z(), z(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wzzy() const
{
    return vector4t<_type>::coord(w(), z(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wzzz()
{
    return _internal::swizzle4(w(), z(), z(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wzzz() const
{
    return vector4t<_type>::coord(w(), z(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wzzw()
{
    return _internal::swizzle4(w(), z(), z(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wzzw() const
{
    return vector4t<_type>::coord(w(), z(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wzwx()
{
    return _internal::swizzle4(w(), z(), w(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wzwx() const
{
    return vector4t<_type>::coord(w(), z(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wzwy()
{
    return _internal::swizzle4(w(), z(), w(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wzwy() const
{
    return vector4t<_type>::coord(w(), z(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wzwz()
{
    return _internal::swizzle4(w(), z(), w(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wzwz() const
{
    return vector4t<_type>::coord(w(), z(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wzww()
{
    return _internal::swizzle4(w(), z(), w(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wzww() const
{
    return vector4t<_type>::coord(w(), z(), w(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wwxx()
{
    return _internal::swizzle4(w(), w(), x(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wwxx() const
{
    return vector4t<_type>::coord(w(), w(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wwxy()
{
    return _internal::swizzle4(w(), w(), x(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wwxy() const
{
    return vector4t<_type>::coord(w(), w(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wwxz()
{
    return _internal::swizzle4(w(), w(), x(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wwxz() const
{
    return vector4t<_type>::coord(w(), w(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wwxw()
{
    return _internal::swizzle4(w(), w(), x(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wwxw() const
{
    return vector4t<_type>::coord(w(), w(), x(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wwyx()
{
    return _internal::swizzle4(w(), w(), y(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wwyx() const
{
    return vector4t<_type>::coord(w(), w(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wwyy()
{
    return _internal::swizzle4(w(), w(), y(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wwyy() const
{
    return vector4t<_type>::coord(w(), w(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wwyz()
{
    return _internal::swizzle4(w(), w(), y(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wwyz() const
{
    return vector4t<_type>::coord(w(), w(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wwyw()
{
    return _internal::swizzle4(w(), w(), y(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wwyw() const
{
    return vector4t<_type>::coord(w(), w(), y(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wwzx()
{
    return _internal::swizzle4(w(), w(), z(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wwzx() const
{
    return vector4t<_type>::coord(w(), w(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wwzy()
{
    return _internal::swizzle4(w(), w(), z(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wwzy() const
{
    return vector4t<_type>::coord(w(), w(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wwzz()
{
    return _internal::swizzle4(w(), w(), z(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wwzz() const
{
    return vector4t<_type>::coord(w(), w(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wwzw()
{
    return _internal::swizzle4(w(), w(), z(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wwzw() const
{
    return vector4t<_type>::coord(w(), w(), z(), w());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wwwx()
{
    return _internal::swizzle4(w(), w(), w(), x());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wwwx() const
{
    return vector4t<_type>::coord(w(), w(), w(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wwwy()
{
    return _internal::swizzle4(w(), w(), w(), y());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wwwy() const
{
    return vector4t<_type>::coord(w(), w(), w(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wwwz()
{
    return _internal::swizzle4(w(), w(), w(), z());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wwwz() const
{
    return vector4t<_type>::coord(w(), w(), w(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector4t<_type>::wwww()
{
    return _internal::swizzle4(w(), w(), w(), w());
}

template <typename _type>
vector4t<_type> vector4t<_type>::wwww() const
{
    return vector4t<_type>::coord(w(), w(), w(), w());
}

