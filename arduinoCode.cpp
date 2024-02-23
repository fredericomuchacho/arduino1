 if(_length != length || _value == nullptr){
    _length = length;
    if( _value != nullptr){
      delete[] _value;
    }
    _value  = new char[_length + 1];  
  }

//edit later
  if(p->getID()){
    for (size_t i = 0; i < strlen(p->getID()); i++){
       if(!(isAlphaNumeric(p->getID()[i])) && !(p->getID()[i]=='_')){
        #ifdef WM_DEBUG_LEVEL
        DEBUG_WM(WM_DEBUG_ERROR,F("[ERROR] parameter IDs can only contain alpha numeric chars"));
        #endif
        return false;
       }
    }
  }

  if(_params == NULL){
    #ifdef WM_DEBUG_LEVEL
    DEBUG_WM(WM_DEBUG_DEV,F("allocating params bytes:"),_max_params * sizeof(WiFiManagerParameter*));        
    #endif
    _params = (WiFiManagerParameter**)malloc(_max_params * sizeof(WiFiManagerParameter*));
  }
