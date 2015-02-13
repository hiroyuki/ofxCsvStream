#pragma once
/*
ofxCsvStream
by
horristic (Hiroyuki Hori)
*/
using namespace std;

class ofxCsvStream
{
public:
	ofxCsvStream(){
		ifs = ofPtr<ifstream>( new ifstream());
		ofs = ofPtr<ofstream>( new ofstream());
	}

    ofxCsvStream(const ofxCsvStream &rhs) {
		ifs = ofPtr<ifstream>( new ifstream());
		ofs = ofPtr<ofstream>( new ofstream());
	}

	ofxCsvStream& operator=(const ofxCsvStream &o){
	  return(*this);
	}

	virtual ~ofxCsvStream()
	{
		closeStream();
	}

	bool openReadStream(string path)
	{
        
		this->path = ofToDataPath( path, true );
		ifs.get()->open( this->path.c_str(), ios::in );
		bool result = ifs.get()->fail();
		if ( result ) ofLogError() << "faild to open " + this->path;
		return !result;
	}

	bool openWriteStream( string path, bool isAppend = false )
	{
		this->path = ofToDataPath( path, true );
        if ( !isAppend )
            ofs.get()->open ( this->path.c_str(), ios::out | ios::trunc );
        else
            ofs.get()->open ( this->path.c_str(), ios::out | ios::app );
		bool result = ofs.get()->fail();
		if ( result ) ofLogError() << "faild to open " + this->path;
		return !result;
	}

	template <class T> ofxCsvStream& operator<< ( const T& value )
	{
		*ofs.get() << value;
		return *this;
	}

	ofxCsvStream& operator<<(std::ostream& (*pf)(std::ostream &))
	{
		pf(*ofs.get());
		return *this;
	}

	void closeStream()
	{
		if ( ofs.get()->is_open() ) ofs.get()->close();
		if ( ifs.get()->is_open() ) ifs.get()->close();
        
	}

	string readNextLine()
	{
        getline( *ifs.get(), currentLine );
        if ( currentTokens.size() > 0 )
        {
            currentTokens.clear();
        }
        parse();
		return currentLine;
	}
    
    void report()
    {
        if ( currentTokens.size() > 0 )
        {
            for ( int i = 0; i < currentTokens.size(); i++)
            {
                cout << currentTokens[i]<<"/";
            }
            cout << endl;
        }
    }

	int getCurrentTokenSize() const
	{
		return currentTokens.size();
	}

	string getCurrentLine() const
	{
		return currentLine;
	}
	
    template <class T> T getValue(const int row) const
	{
		T result;
		if ( row < currentTokens.size() )
			result = ofFromString<T>( currentTokens[row] );
		else
			ofLog() << "line doesn't have item at " << row;
		return result;
	}

	bool eof()
	{
		return ifs.get()->eof();
	}

private:
	ofPtr<ifstream> ifs;
	ofPtr<ofstream> ofs;
	string currentLine;
	vector< string > currentTokens;
	string path;

	void parse()
	{
        char* token = NULL;
		do
		{
			token = strtok( token == NULL ? const_cast<char  *>(currentLine.c_str()) : NULL, "," );
            if ( token != NULL ) currentTokens.push_back(string( token ));
        }while( token != NULL );
	}

	void clearTokens()
	{
		currentTokens.clear();
	}
};