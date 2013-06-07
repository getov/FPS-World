_type& y()
{
    return this->at(1);
}

const _type& y() const
{
    return this->at(1);
}

vector2t<_type>& xy()
{
    return *reinterpret_cast<vector2t<_type>*>(this->as_array());
}

const vector2t<_type>& xy() const
{
    return *reinterpret_cast<vector2t<_type>*>(this->as_array());
}
