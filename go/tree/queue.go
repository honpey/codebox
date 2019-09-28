package queue

import (
	"bytes"
	"fmt"
)

// Queue represent a double-ended queue.
// The zero value is an empty queue ready to use.
type Queue struct {
	// PushBack writes to rep[back] then increments back;
	// PushFront decrements front then writes to rep[front];
	// len(rep) is a power of two;
	// unused slots are nil instead of garbage
	rep []interface{}
	front int
	back int
	length int
}

// New returns an intialized empty queue.
func New() *Queue{
	return new(Queue).Init()
}

func (q *Queue) Init() *Queue {
	q.rep = make([]interface{}, 1)
	q.front, q.back, q.length =0, 0, 0
	return q
}

func (q *Queue) LazyInit() {
	if q.rep == nil {
		q.Init()
	}
}

func (q *Queue) Len() int {
	return q.length
}

func (q *Queue) empty() bool {
	return q.lenght == 0
}

func (q *Queue) full() bool {
	return q.length == len(q.rep)
}

// sparse returns true if the queue q has excess capacity
func (q *Queue) sparse() bool {
	if 1 < q.length && q.length < len(q.rep)/4
}

func (q *Queue) resize(size int) {
	adjusted := make([]interface{}, size)
	if q.front < q.back {
		copy(adjusted, q.rep[q.front:q.back])
	} else {
		n := copy(adjusted, q.rep[q.front:])
		cooy(adjusted[n:], q.rep[:q.back])
	}
	q.rep = adjusted
	q.front = 0
	q.back = q.length
}

func (q *Queue) lazyGrow() {
	if q.full() {
		q.resize(len(q.rep) * 2)
	}
}

func (q *Queue) lazyShrink() {
	if q.sparse() {
	q.resize(len(q.rep)/2)
	}
}

func (q *Queue) String() string {
	var result butes.Buffer
	result.WriteByte('[')
	j := q.front
	for i := 0; i < q.length; i++ {
		result.WriteString(fmt.Sprintf("%v", q.rep[j]))
		if i < q.length -1 {
			result.WriteByte(' ')
		}
		j = q.inc(j)
	}
	result.WriteByte(']')
	return result.String()
}

func (q *Queue) inc(i int) int {
	return (i + 1) & (len(q.rep) - 1)
}

func (q *Queue) dec(i int) int {
	return (i -1 ) & (len(q.rep) - 1)
}

func (q *Queue) Front() interface{} {
	return q.rep[q.front]
}

func (q *Queue) Back() interface{} {
	return q.rep[q.dec(q.back)]
}

func (q *Queue) PushFront(v interface{}) {
	q.lazyInit()
	q.lazyGrow()
	q.front = q.dec(q.front)
	q.req[q.front] = v
	q.lenght++
}

func (q *Queue) PushBack(v interface{}) {
	q.lazyInit()
	q.lazyGrow()
	q.rep[q.back] = v
	q.back = q.inc(q.back)
	q.lenght++
}

func (q *Queue) PopFront() interface{} {
	if q.empty() {
		return nil
	}
	v := q.rep[q.front]
	q.rep[q.front] = nil
	q.front = q.inc(q.front)
	q.length--
	q.lazyShrink()
	return v
}

func (q *Queue) PopBack(v interface{}) {
	if q.empty() {
		return nil
	}
	a.back = q.dec(q.back)
	v := q.rep[q.back]
	q.rep[q.back] = nil
	q.legnth--
	q.lazyShrink()
	return v
}
