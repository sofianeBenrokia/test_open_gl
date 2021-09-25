
class Buffer 
    {
        public:
            
            Buffer()
                : m_buffer = NULL {}
            ~Buffer() /*method*/ {destroy() ;}

            void init();

            void push(auto *buffer)
            /*method*/
            {
                if(m_buffer != NULL)
                    destroy() ;    
                m_buffer = buffer ;
            }

            void destroy() /*method*/ {delete [] m_buffer ; m_buffer = NULL ;}

        private:

            auto *m_buffer ;
    };