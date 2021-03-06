#include <iostream>
#include <string>
#include <queue> 
#include <vector>
using namespace std;

int maxElemLength( const vector<int>& v );
int GetDigit( int number, int k );
vector<queue<int> > ItemsToQueues( const vector< int >& L, int k );
vector<int> QueuesToArray( vector<queue<int> >& QA, int numVals );
void RadixSort( vector<int>& L, int numDigits );
void PrintVector( const vector<int>& L ); 

int main( ) 
{
    vector<int> L{ 380, 95, 345, 382, 260, 100, 492 };  // to be sorted

    cout << "Before Sort:\n";
    PrintVector( L ); 
    RadixSort( L, maxElemLength( L ) );
    cout << "\nAfter Sort:\n";
    PrintVector( L );
    return 0;
}

int maxElemLength( const vector<int>& v ) 
{
    int max = 0;
    string curr;
    for( int i = 0; i < v.size(); i++ ) {
        curr = to_string( v[ i ] );
        if( curr.length() > max )
            max = curr.length();
    }

    return max;
}

int GetDigit( int number, int k )
{
   for( int i = 0; i < k; i++ )
       number /= 10;

   return( number % 10 );
}

vector<queue<int> > ItemsToQueues( const vector< int >& L, int k )
{
    vector<queue<int> > QA( 10 );

    for( int i = 0; i < L.size(); i++ ) {
        int num = GetDigit( L[ i ], k );
        QA[ num ].push( L[ i ] );
    }

    return QA;
}

vector<int> QueuesToArray( vector<queue<int> >& QA, int numVals ) 
{
    vector<int> array ( numVals );
    int pos = 0;
    for( int i = 0; i < QA.size(); i++ ) {
        int inner = QA[ i ].size();
        for( int j = 0; j < inner; j++ ) {
            array[ pos++ ] = QA[ i ].front();
            QA[ i ].pop();
        }
    }

    return array;
}

void RadixSort( vector<int>& L, int numDigits )
{
    vector<queue<int> > QA( 10 );
    for( int i = 0; i < numDigits; i++ ) {
        QA = ItemsToQueues( L, i );
        L = QueuesToArray( QA, L.size() );
    }
}

void PrintVector( const vector<int>& L ) 
{
    for( int i = 0; i < L.size(); i++ ) {
        cout << L[ i ] << " ";
    }
    cout << "\n";
}