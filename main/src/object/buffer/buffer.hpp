
class Buffer 
    {
        public:
            
            Buffer()
                : m_data = NULL {}
            
            ~Buffer() /*method*/ {destroy() ;}

            /*
            * void init(unsigned int &index_vertex_attrib_array, -> (index_vertex_attrib_array: )
            *          unsigned int &size,                       -> (size: )
            *          unsigned int &type,                       -> (type: )
            *          auto *data)                               -> (data: )
            */
            void init(unsigned int &index_vertex_attrib_array,
                     unsigned int &size,
                     unsigned int &type,
                     auto *data)
            /*method*/
                {
                    push(data) ;
                    m_index_vertex_attrib_array = index_vertex_attrib_array ;
                    glGenBuffers(1 , &m_buffer_id) ;
                    bind() ;
                    glBufferData(GL_ARRAY_BUFFER , sizeof(*m_data) , m_data , GL_STATIC_DRAW) ;
                    glEnableVertexAttribArray(m_index_vertex_attrib_array) ;
                    int normalized = type == GL_FLOAD ? GL_FALSE : GL_TRUE ;
                    glVertexAttribPointer(m_index_vertex_attrib_array , size , type ,
                                         normalized , size * sizeof(decltype(*m_data)) , NULL) ;

                } ;

            /*
            * push(auto *data) -> (*data: the pointer of the memory zone you want to use)
            *               --------
            *     change data use.
            */
            void push(auto *data)
            /*method*/
            {
                if(m_data != NULL)
                    clear() ;    
                m_data = data ;
            }

            void bind() /*method*/ {glBindBuffer(GL_ARRAY_BUFFER , m_buffer_id) ;} ;

            void unbind() /*method*/ {glBindBuffer(GL_ARRAY_BUFFER , 0) ;} ;

            void clear() /*method*/ {m_data = NULL ;}

            void destroy() ;

        private:

            auto *m_data ;
            unsigned int m_buffer_id ;
            unsigned int m_index_vertex_attrib_array ;
    };